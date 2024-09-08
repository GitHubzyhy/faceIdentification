#include "widget.h"
#include "ui_widget.h"
#include <QDataStream>
#include <opencv.hpp>
#include <QDateTime>
#include <QThread>
#include <QSqlError>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 当有客户端连接时，触发 newConnection 信号
    // 并将其连接到 accept_client 槽函数
    connect(&m_server, &QTcpServer::newConnection, this, &Widget::accept_client);
    // 监听指定的IP地址和端口，启动TCP服务器
    m_server.listen(QHostAddress::Any, 9999);
    bsize = 0;

    //给sql模型绑定表格
    model.setTable("employee");

    QThread *thread = new QThread;
    //把QfaceObject的对象移动到线程中执行
    fobj.moveToThread(thread);
    //启动线程
    thread->start();
    //绑定查询槽函数
    connect(this, &Widget::query, &fobj, &QFaceObject::face_query);
    //关联QFaceObject对象里面的send_faceid信号
    connect(&fobj, &QFaceObject::send_faceid, this, &Widget::recv_faceid);

    exeSql.exec("DELETE FROM  attendance");
    exeSql.exec("DELETE FROM  sqlite_sequence WHERE name =\'attendance\'");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::accept_client()
{
    //获取与客户端通信的套接字
    m_socket = m_server.nextPendingConnection();
    // 当套接字有数据到达时，触发 readyRead 信号
    // 并将其连接到 read_data 槽函数
    connect(m_socket, &QTcpSocket::readyRead, this, &Widget::read_data);
}

void Widget::read_data()
{
    // 创建 QDataStream 对象，并设置其版本为 Qt_6_7
    QDataStream dsIn(m_socket);//把套接字绑定到数据流
    dsIn.setVersion(QDataStream::Qt_6_7);

    // 如果 bsize 为零，则检查套接字中是否有足够的数据读取数据大小
    if (bsize == 0)
    {
        //先读取文件大小
        if (m_socket-> bytesAvailable() < (qint64) sizeof(bsize)) return;
        dsIn >> bsize;
    }
    // 检查套接字中是否有足够的数据读取图像数据
    if (m_socket->bytesAvailable() < (qint64)bsize) return;

    // 读取图像数据并将其赋予 data
    QByteArray data;
    dsIn >> data;

    bsize = 0;// 将 bsize 重置为零
    // 如果 data 为空，则返回
    if (data.size() == 0) return;

    // 使用 loadFromData() 函数从 data 中加载图像
    QPixmap m_mp;
    if (!m_mp.loadFromData(data, "jpg"))
        return;//加载图像失败，可能是数据损坏或格式错误

    // 将图像缩放到 QLabel 控件的大小
    m_mp = m_mp.scaled(ui->picLb->size());
    // 将图像显示在 QLabel 控件上
    ui->picLb->setPixmap(m_mp);

    //-----------------识别人脸------------------//
    // 定义一个 OpenCV 的 Mat 对象，用于存储人脸图像
    cv::Mat faceImage;
    // 定义一个无符号字符型向量 decode，用于存储解码后的数据
    std::vector<uchar> decode;

    // 调整 decode 的大小为与 data 相同
    decode.resize(data.size());

    // 将数据从 data 拷贝到 decode 中
    memcpy(decode.data(), data.data(), data.size());

    // 对解码后的数据进行颜色图像格式的解码，得到人脸图像
    faceImage = cv::imdecode(decode, cv::IMREAD_COLOR);

    // 使用 face_query 函数查询人脸，获取人脸ID
    // int faceID = fobj.face_query(faceImage);//运行时间比较长
    emit query(faceImage);

}
void Widget::recv_faceid(int64_t faceid)
{
    qDebug() << "人脸ID" << faceid;// 输出人脸ID信息
    //没有检测到人脸，也得发送空的数据
    if (faceid < 0)
    {
        QString sdmsg = QString("{\"employeeID\":,\"name\":,\"address\":,\"time\":}");
        // 发送数据
        m_socket->write(sdmsg.toUtf8());
        return;
    }

    // -----------------从数据库中提取数据------------------//
    // 给模型设置过滤器
    model.setFilter(QString("faceID=%1").arg(faceid));
    model.select();//查询，将对应的数据提取出来
    // 检查是否成功提取到一条记录
    if (model.rowCount() == 1)
    {
        //获取第一行记录
        QSqlRecord record = model.record(0);
        QString imagPath = record.value("headfile").toString();
        // 构建要发送的 JSON 消息
        QString sdmsg = QString("{\"employeeID\":\"%1\",\"name\":\"%2\",\"address\":\"%3\",\"time\":\"%4\"}")
                        .arg(record.value("employeeID").toString()) // 员工ID
                        .arg(record.value("name").toString()) // 姓名
                        .arg(record.value("address").toString()) // 地址
                        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));// 当前时间

        //把打包好的数据发送给客户端
        m_socket->write(sdmsg.toUtf8());

        //把数据写入考勤表
        //时间是系统默认生成不需要加入
        QString insertstr = QString("INSERT INTO attendance(employeeID) VALUES (%1)")
                            .arg(record.value("employeeID").toString());
        qDebug() << insertstr;

        if (!exeSql.exec(insertstr))
            qDebug() << "sql语句执行失败" + exeSql.lastError().text();
    }
}

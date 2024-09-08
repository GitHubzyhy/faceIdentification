#include "widget.h"
#include "ui_widget.h"
#include <QCloseEvent>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QHostInfo>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //如果在linux上就必须改成/dev/video
    cap.open(0);//打开索引为0的摄像头
    //启动定时器，每多少毫秒采集一次
    timerId = startTimer(0);

    //导入级联分类器文件
    cascade.load("D:/Environment/opencv452/etc/haarcascades/haarcascade_frontalface_alt2.xml");

    //QTcpSocket当断开连接的时候disconnected信号，连接成功会发送connected
    connect(&m_socket, &QTcpSocket::disconnected, this, [this]
    {
        //断开连接后5s就尝试连接一次，指导连接成功
        m_timer.start(5000);
        qDebug() << "服务器断开";
    });
    connect(&m_socket, &QTcpSocket::connected, this, [this]
    {
        //连接成功后就停止5s一次尝试连接
        m_timer.stop();
        qDebug() << "连接成功";
    });

    //定时尝试连接服务器
    connect(&m_timer, &QTimer::timeout, this, [this]
    {
        //定时连接服务器
        m_socket.connectToHost(QHostAddress::LocalHost, 9999);
    });
    //接受json数据槽函数连接
    connect(&m_socket, &QTcpSocket::readyRead, this, &Widget::recv_data);
    //启动定时器,每5s连接一次直到成功
    m_timer.start(5000);
    m_socket.connectToHost(QHostAddress::LocalHost, 9999);

    timer.start();
    curTime = timer.elapsed();

    resetAll();
}

Widget::~Widget()
{
    delete ui;
}

//解析服务端传过来的json数据
void Widget::recv_data()
{
    //{employeeID:%1, name : %2,address:%3,time:%4}
    // 接受数据并展示
    QByteArray array = m_socket.readAll(); // 读取所有接收到的数据

    // JSON解析
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(array, &err);
    // 检查JSON解析错误
    if (err.error != QJsonParseError::NoError)
    {
        qDebug() << "Json格式错误";
        resetAll();
        return;
    }

    //获取json对象
    QJsonObject obj = doc.object();
    // 获取员工ID、姓名、时间和地址信息
    QString employeeID = obj.value("employeeID").toString(); // 员工ID
    QString name = obj.value("name").toString(); // 姓名
    QString timestr = obj.value("time").toString(); // 时间字符串
    QString address = obj.value("address").toString(); // 地址

    // 更新界面显示
    ui->employeeID->setText(employeeID); // 员工ID标签
    ui->nickname->setText(name); // 姓名标签
    ui->address->setText(address); // 地址标签
    ui->time->setText(timestr); // 时间标签

    //receive_data接受数据显示信息时把头像也加上
    //-----------------显示头像------------------
    ui->headLb->setStyleSheet("border-radius:70px; border-image: url(./cache.jpg);");
    //显示认证成功
    ui->widgetlb->show();
}
//没有检测到人脸时，重置所有显示
void Widget::resetAll()
{
    //设置是否认证成功
    ui->widgetlb->hide();//隐藏

    ui->headLb->setStyleSheet("border-radius:70px;");
    // 更新界面显示
    ui->employeeID->clear(); // 员工ID标签
    ui->nickname->clear(); // 姓名标签
    ui->address->clear(); // 地址标签
    ui->time->clear(); // 时间标签
}

void Widget::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);

    //采集数据
    // Mat srcImage;
    if (cap.grab())
    {
        cap.read(srcImage);
        // 水平镜像图像
        cv::flip(srcImage, srcImage, 1);
    }

    //把图像转为灰度图，提高处理速度
    Mat grayImage;
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    //检测人脸数据
    std::vector<Rect> faceRects;//数据会存储在这个容器里
    cascade.detectMultiScale(grayImage, faceRects);
    if (faceRects.size() > 0 ) //说明检测到人脸
    {
        Rect rect = faceRects.at(0);//第一个人脸的矩形框

        //绘制矩形框
        // rectangle(srcImage, rect, Scalar(0, 0, 255));
        ui->headpicLb->setGeometry(rect.x, rect.y, rect.width, rect.height);
        //移动人脸框（图片--QLabel）
        ui->headpicLb->move(rect.x, rect.y);

        if (timer.elapsed() - curTime > 1000)
        {
            curTime = timer.elapsed();
            flag = true;
        }
        else
            flag = false;
        if (flag)
        {
            //把Mat数据转化为QbyteArry,编码成jpg格式
            vector<uchar> buf;
            cv::imencode(".jpg", srcImage, buf);//编码数据存到buf里去
            QByteArray byte((const char *)buf.data(), buf.size());

            //准备发送①文件大小②文件数据
            quint64 backsize = byte.size();// 获取数据大小
            QByteArray sendData;// 创建用于发送数据的 QByteArray 对象

            // 创建 QDataStream 对象，用于将数据写入 sendData
            QDataStream stream(&sendData, QIODevice::WriteOnly);
            stream.setVersion(QDataStream::Qt_6_7); // 设置 QDataStream 的版本

            // 将数据大小和字节数据写入 sendData
            stream << backsize << byte;

            // 将数据发送给服务端
            m_socket.write(sendData);
            //检测到人脸发送数据时保存一下这个人脸的图片
            //保存终端显示的人脸数据
            cv::Mat faceMat = srcImage(rect);
            cv::imwrite("./cache.jpg", faceMat);
        }
    }
    else
    {
        //没有检测到人脸就让人脸框恢复初始状态
        ui->headpicLb->setGeometry(100, 60, 266, 266);
        resetAll();
    }

    //没有数据返回
    if (srcImage.data == NULL)
        return;
    // 将 OpenCV 的 Mat 格式（BGR）转换为 Qt 的 QImage 格式（RGB）
    cvtColor(srcImage, srcImage, COLOR_BGRA2RGB);

    // 将 Mat 数据转换为 QImage
    QImage image(srcImage.data, srcImage.cols, srcImage.rows, srcImage.step1(), QImage::Format_RGB888);

    // 将 QImage 转换为 QPixmap
    QPixmap mmp = QPixmap::fromImage(image);

    // 将 QPixmap 显示在 QLabel 控件上
    ui->videoLb->setPixmap(mmp);
}

void Widget::closeEvent(QCloseEvent *event)
{
    killTimer(timerId);
    cap.release();//释放摄像头资源
    event->accept();
}

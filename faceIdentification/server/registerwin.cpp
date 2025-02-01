#include "registerwin.h"
#include "ui_registerwin.h"
#include <QFileDialog>
#include "qfaceobject.h"
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>

RegisterWin::RegisterWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterWin)
{
    ui->setupUi(this);
}

RegisterWin::~RegisterWin()
{
    delete ui;
}
//重置
void RegisterWin::on_resetBt_clicked()
{
    //清空数据
    ui->nameEdit->clear();
    ui->birthdayEdit->setDate(QDate::currentDate());
    ui->addressEdit->clear();
    ui->phoneEdit->clear();
    ui->picFileEdit->clear();
}
//添加头像
void RegisterWin::on_addpicBt_clicked()
{
    //通过文件对话框选中文件
    QString filePath = QFileDialog::getOpenFileName(
                           this,
                           "选择图片",
                           "../../");
    if (filePath.isEmpty()) return;
    ui->picFileEdit->setText(filePath);

    //显示图片,在图片标签中显示缩放后的图片
    QPixmap pixmap(filePath);
    ui->headpicLb->setPixmap(pixmap.scaled(ui->headpicLb->size()));
}
//注册
void RegisterWin::on_registerBt_clicked()
{
    //1、通过照片，结合faceobject模块得到faceID
    QFaceObject faceobject;
    cv::Mat image = cv::imread(ui->picFileEdit->text().toUtf8().data());
    int faceID = faceobject.face_register(image);//自己写的接口
    qDebug() << faceID;

    //2、把个人信息储存到employee表
    QSqlTableModel model;
    model.setTable("employee");
    //把头像保存到一个路径下
    QString headfile = QString("../../data/%1.jpg").arg(faceID);
    cv::imwrite(headfile.toStdString(), image);//将image数据写到指定目录下
    QSqlRecord record = model.record();

    // 设置记录的各个字段值
    record.setValue("name", ui->nameEdit->text());
    record.setValue("sex", ui->mrb->isChecked() ? "男" : "女");
    record.setValue("birthday", ui->birthdayEdit->text());
    record.setValue("address", ui->addressEdit->text());
    record.setValue("phone", ui->phoneEdit->text());
    record.setValue("faceID", faceID);
    record.setValue("headfile", headfile);

    //3、提示注册成功
    // 插入记录到模型
    bool ret = model.insertRecord(0, record);
    if (ret)
    {
        // 提交所有的挂起的更改到数据库
        model.submitAll();
        QMessageBox::information(nullptr, "信息", "注册成功");
    }
    else
        QMessageBox::information(nullptr, "信息", "注册失败，头像重复或信息错误");
}
//打开摄像头
void RegisterWin::on_videoswitchBt_clicked()
{
    // 检查按钮文本，如果当前为“打开摄像头”
    if (ui->videoswitchBt->text() == "打开摄像头")
    {
        // 打开摄像头
        if (cap.open(0)) // 尝试打开摄像头设备（设备编号为0）
        {
            ui->videoswitchBt->setText("关闭摄像头"); // 设置按钮文本为“关闭摄像头”
            timerID = startTimer(100); // 启动定时器，以每100毫秒的间隔捕获摄像头图像
        }
    }
    else // 如果当前按钮文本不是“打开摄像头”，即为“关闭摄像头”
    {
        killTimer(timerID); // 停止定时器
        ui->videoswitchBt->setText("打开摄像头"); // 设置按钮文本为“打开摄像头”
        // 关闭摄像头
        cap.release(); // 释放摄像头资源
        ui->headpicLb->clear();
    }
}
//拍照
void RegisterWin::on_cameraBt_clicked()
{
    QString headfile = QString("../../data/%1.jpg").arg(ui->nameEdit->text().toUtf8().toBase64());
    ui->picFileEdit->setText(headfile);//注册功能需要用到这个内容
    cv::flip(srcImage, srcImage, 1);// 水平翻转图像
    cv::imwrite(headfile.toStdString(), srcImage);//将image数据写到指定目录下

    killTimer(timerID); // 停止定时器
    ui->videoswitchBt->setText("打开摄像头"); // 设置按钮文本为“打开摄像头”
    // 关闭摄像头
    cap.release(); // 释放摄像头资源
    QMessageBox::information(nullptr, "信息", "拍照成功");
}

void RegisterWin::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    // 获取摄像头数据
    if (cap.isOpened()) // 如果摄像头成功打开
    {
        cap >> srcImage; // 从摄像头读取图像帧
        if (srcImage.data == nullptr) return; // 如果图像数据为空，则返回
    }

    // 将图像格式转换为Qt能够处理的格式
    cv::Mat outImage;
    cv::cvtColor(srcImage, outImage, cv::COLOR_BGR2RGB); // 将图像从BGR格式转换为RGB格式（OpenCV默认的颜色通道顺序与Qt不同）
    cv::flip(outImage, outImage, 1); // 水平翻转图像，因为摄像头的图像可能是镜像的

    QImage image(outImage.data, outImage.cols, outImage.rows, outImage.step1(), QImage::Format_RGB888); // 创建Qt的QImage对象

    // 在Qt界面上显示图像
    QPixmap mmp = QPixmap::fromImage(image); // 将QImage转换为QPixmap
    mmp = mmp.scaled(ui->headpicLb->size()); // 根据标签的宽度缩放图像
    ui->headpicLb->setPixmap(mmp); // 将图像显示在标签上
}

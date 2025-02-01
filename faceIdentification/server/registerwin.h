#ifndef REGISTERWIN_H
#define REGISTERWIN_H

#include <QWidget>
#include <opencv.hpp>

namespace Ui
{
    class RegisterWin;
}

class RegisterWin : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWin(QWidget *parent = nullptr);
    ~RegisterWin();
private slots:
    void on_resetBt_clicked();//重置
    void on_addpicBt_clicked();//添加头像
    void on_registerBt_clicked();//注册
    void on_videoswitchBt_clicked();//打开摄像头
    void on_cameraBt_clicked();//拍照
private:
    Ui::RegisterWin *ui;

    int timerID;
    cv::VideoCapture cap;
    cv::Mat srcImage;

    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) override;
};

#endif // REGISTERWIN_H

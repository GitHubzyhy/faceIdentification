#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <opencv.hpp>
#include <QTcpSocket>
#include <QTimer>
#include <QElapsedTimer>

using namespace cv;
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui
{
    class Widget;
}
QT_END_NAMESPACE

class Client : public QWidget
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();

    void initSocket();//网络初始化
    void sendData(const Rect &rect);//向服务器发送数据
    void recv_data();//解析服务端传过来的json数据
    void resetAll();//没有检测到人脸时，重置所有显示
private:
    Ui::Widget *ui;

    Mat srcImage;
    int timerId;
    VideoCapture cap;//摄像头

    cv::CascadeClassifier cascade; //haar--级联分类器

    //创建网络前套字，定时器
    QTcpSocket m_socket;
    QTimer m_timer;

    //优化相关
    int curTime;
    QElapsedTimer timer;
    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void closeEvent(QCloseEvent *event) override;
};
#endif // CLIENT_H

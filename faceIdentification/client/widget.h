#ifndef WIDGET_H
#define WIDGET_H

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

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void recv_data();//解析服务端传过来的json数据
    void resetAll();//没有检测到人脸时，重置所有显示
private:
    Ui::Widget *ui;

    int timerId;
    VideoCapture cap;//摄像头
    Mat srcImage;

    cv::CascadeClassifier cascade; //haar--级联分类器

    //创建网络前套字，定时器
    QTcpSocket m_socket;
    QTimer m_timer;

    //优化相关
    bool flag = true;
    int curTime;
    QElapsedTimer timer;
    // QObject interface
protected:
    virtual void timerEvent(QTimerEvent *event) override;
    virtual void closeEvent(QCloseEvent *event) override;
};
#endif // WIDGET_H

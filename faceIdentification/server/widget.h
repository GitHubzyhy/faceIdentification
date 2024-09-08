#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>
#include <QTcpServer>
#include "qfaceobject.h"//注册查询人脸
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQuery>

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

public slots:
    void accept_client();// 接受客户端连接的槽函数
    void read_data();// 读取数据的槽函数
    void recv_faceid(int64_t faceid);//获取查询得到的人脸ID

signals:
    void query(cv::Mat &image);

private:
    Ui::Widget *ui;

    QTcpServer m_server;//TCP服务器对象
    QTcpSocket *m_socket;//与客户端通信的套接字对象
    quint64 bsize;//传输文件的大小

    QFaceObject fobj;

    QSqlTableModel model;
    QSqlQuery exeSql;
};
#endif // WIDGET_H

#include "widget.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>//执行任意sql语句
#include <QSqlError>
#include <opencv.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qRegisterMetaType <cv::Mat>("cv::Mat&");
    qRegisterMetaType <cv::Mat>("cv::Mat");
    qRegisterMetaType <int64_t>("int64_t");

    // 连接到 SQLite 数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE"); //添加数据库驱动
    db.setDatabaseName("../../database/server.db");
    // 检查数据库连接是否成功
    if (!db.open())
    {
        qDebug() << db.lastError().text();
        return -1; // 程序退出并返回错误代码
    }

    // 创建员工信息表 (if not exists: 如果不存在)
    QString createstr = "create table if not exists employee(employeeID integer primary key autoincrement, name text , sex text,"
                        "birthday text, address text, phone text, faceID integer unique, headfile text)";

    // 创建 SQL 查询对象
    QSqlQuery query;
    if (!query.exec(createstr))
        qDebug() << query.lastError().text();

    // 创建考勤记录表 (if not exists: 如果不存在则创建)
    createstr = "create table if not exists attendance(attendenceID integer primary key autoincrement, employeeID integer,"
                "attendanceTime TimeStamp NOT NULL DEFAULT(datetime('now','localtime')))";

    if (!query.exec(createstr))
        qDebug() << query.lastError().text();

    Widget w;
    w.show();

    return a.exec();
}

#include "selectwin.h"
#include "ui_selectwin.h"
#include <QSqlTableModel>

SelectWin::SelectWin(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectWin)
{
    ui->setupUi(this);

    model = new QSqlTableModel;
}

SelectWin::~SelectWin()
{
    delete ui;
}
//设置表头
void SelectWin::changeHeader(bool flag)
{
    if (flag)
    {
        model->setHeaderData(model->fieldIndex("employeeID"), Qt::Horizontal, "员工号");
        model->setHeaderData(model->fieldIndex("name"), Qt::Horizontal, "姓名");
        model->setHeaderData(model->fieldIndex("sex"), Qt::Horizontal, "性别");
        model->setHeaderData(model->fieldIndex("birthday"), Qt::Horizontal, "生日");
        model->setHeaderData(model->fieldIndex("address"), Qt::Horizontal, "地址");
        model->setHeaderData(model->fieldIndex("phone"), Qt::Horizontal, "电话");
        model->setHeaderData(model->fieldIndex("faceID"), Qt::Horizontal, "脸部ID");
        model->setHeaderData(model->fieldIndex("headfile"), Qt::Horizontal, "头像路径");
    }
    else
    {
        model->setHeaderData(model->fieldIndex("phone"), Qt::Horizontal, "电话");
        model->setHeaderData(model->fieldIndex("attendenceID"), Qt::Horizontal, "考勤编号");
        model->setHeaderData(model->fieldIndex("employeeID"), Qt::Horizontal, "员工号");
        model->setHeaderData(model->fieldIndex("attendanceTime"), Qt::Horizontal, "考勤时间");
    }
}
//查询
void SelectWin::on_selectBt_clicked()
{
    if (ui->empRb->isChecked())
    {
        model->setTable("employee");//设置员工表格
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
        changeHeader(true);
    }
    else if (ui->attRb->isChecked())
    {
        model->setTable("attendance");
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );
        changeHeader(false);
    }
    //查询数据
    model->select();
    ui->tableView->setModel(model);
}

#ifndef SELECTWIN_H
#define SELECTWIN_H

#include <QWidget>

namespace Ui
{
    class SelectWin;
}

class QSqlTableModel;
class SelectWin : public QWidget
{
    Q_OBJECT

public:
    explicit SelectWin(QWidget *parent = nullptr);
    ~SelectWin();

    void changeHeader(bool);//设置表头
private slots:
    void on_selectBt_clicked();

private:
    Ui::SelectWin *ui;
    QSqlTableModel *model;
};

#endif // SELECTWIN_H

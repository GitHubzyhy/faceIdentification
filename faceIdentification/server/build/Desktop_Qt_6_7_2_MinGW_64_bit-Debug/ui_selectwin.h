/********************************************************************************
** Form generated from reading UI file 'selectwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTWIN_H
#define UI_SELECTWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectWin
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *empRb;
    QRadioButton *attRb;
    QPushButton *selectBt;
    QTableView *tableView;

    void setupUi(QWidget *SelectWin)
    {
        if (SelectWin->objectName().isEmpty())
            SelectWin->setObjectName("SelectWin");
        SelectWin->resize(765, 454);
        SelectWin->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(SelectWin);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(SelectWin);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget \n"
"{\n"
"	background-color: rgb(66, 74, 80);\n"
"	font: 25 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QPushButton \n"
"{\n"
"	width: 248;\n"
"	height: 27;\n"
"	border: 1px groove rgb(0, 255, 127);\n"
"	border-radius: 7px;\n"
"	color: rgb(0, 255, 127);\n"
"}\n"
"\n"
"QPushButton::hover \n"
"{\n"
"	background-color: rgb(0, 255, 127);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"\n"
"QPushButton::pressed \n"
"{\n"
"	background-color: rgb(66, 74, 80);\n"
"	border: 1px solid rgb(0, 255, 127);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QRadioButton::indicator \n"
"{\n"
"	width: 13px;\n"
"	height: 13px;\n"
"	border-radius: 8px;\n"
"	border: 2px solid rgb(0, 255, 127);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"	width: 13px;\n"
"	height: 13px;\n"
"	border-radius: 8px;\n"
"	background-color: rgb(0, 255, 127);\n"
"}\n"
"\n"
"QTableView\n"
"{\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"	gridline-color: rgb(255, 255, 255);\n"
""
                        "}\n"
"\n"
"QTableView::item:selected \n"
"{ \n"
"	background-color: rgb(0, 255, 255);\n"
"	color: rgb(0, 0, 0); \n"
"}\n"
"\n"
"QScrollBar:horizontal \n"
"{\n"
"    border: none;\n"
"    background: #2B2B2B;  /* \347\251\272\351\232\231\351\203\250\345\210\206\347\232\204\351\242\234\350\211\262 */\n"
"    height: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal \n"
"{\n"
"    background: rgb(0, 255, 127);  /* \346\273\221\345\235\227\347\232\204\351\242\234\350\211\262 */\n"
"    min-width: 20px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal,\n"
"QScrollBar::sub-line:horizontal \n"
"{\n"
"    border: none;   /* \347\247\273\351\231\244\345\267\246\345\217\263\344\270\244\347\253\257\346\214\211\351\222\256 */\n"
"    background: none;\n"
"    width: 0px;     /* \347\241\256\344\277\235\344\270\215\344\274\232\345\215\240\347\224\250\345\244\232\344\275\231\347\232\204\347\251\272\351\227\264 */\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal,/\n"
"QScrollBar::sub-page:horizontal "
                        "\n"
"{\n"
"    background: #444444;  /* \346\273\221\345\235\227\344\271\213\345\244\226\347\232\204\347\251\272\347\231\275\351\203\250\345\210\206\351\242\234\350\211\262 */\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        empRb = new QRadioButton(widget);
        empRb->setObjectName("empRb");
        empRb->setChecked(true);

        horizontalLayout->addWidget(empRb);

        attRb = new QRadioButton(widget);
        attRb->setObjectName("attRb");
        attRb->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(attRb);

        selectBt = new QPushButton(widget);
        selectBt->setObjectName("selectBt");
        selectBt->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(selectBt);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(widget);
        tableView->setObjectName("tableView");
        tableView->setStyleSheet(QString::fromUtf8(""));
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollMode::ScrollPerPixel);

        verticalLayout->addWidget(tableView);


        verticalLayout_2->addWidget(widget);


        retranslateUi(SelectWin);

        QMetaObject::connectSlotsByName(SelectWin);
    } // setupUi

    void retranslateUi(QWidget *SelectWin)
    {
        SelectWin->setWindowTitle(QCoreApplication::translate("SelectWin", "Form", nullptr));
        empRb->setText(QCoreApplication::translate("SelectWin", "\345\221\230\345\267\245", nullptr));
        attRb->setText(QCoreApplication::translate("SelectWin", "\350\200\203\345\213\244", nullptr));
        selectBt->setText(QCoreApplication::translate("SelectWin", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectWin: public Ui_SelectWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTWIN_H

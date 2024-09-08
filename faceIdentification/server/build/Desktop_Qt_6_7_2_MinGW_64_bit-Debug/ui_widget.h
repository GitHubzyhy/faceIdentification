/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <registerwin.h>
#include <selectwin.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *showWidget;
    QLabel *picLb;
    RegisterWin *registerWidget;
    SelectWin *selectWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(803, 455);
        Widget->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	background-color: #424a50;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab \n"
"{\n"
" 	padding: 3px;               /* \345\206\205\350\276\271\350\267\235\357\274\214\345\242\236\345\212\240\351\200\211\351\241\271\345\215\241\345\206\205\345\256\271\347\232\204\347\251\272\351\227\264 */\n"
"	margin-right: 2px;          /* \346\216\247\345\210\266\351\200\211\351\241\271\345\215\241\344\271\213\351\227\264\347\232\204\350\267\235\347\246\273 */\n"
"	border: 2px solid rgb(255, 255, 255);  /* \350\276\271\346\241\206\351\242\234\350\211\262\347\225\245\346\267\261\344\272\216\350\203\214\346\231\257\350\211\262 */	\n"
"	border-radius: 5px;         /* \345\234\206\350\247\222\345\215\212\345\276\204\357\274\2145px \346\230\257\345\260\217\347\232\204\345\234\206\350\247\222\346\225\210\346\236\234 */\n"
"\n"
"	color: rgb(255, 255, 255);\n"
"	background-color: rgb(0, 0, 0);\n"
"	font: 16pt \"Microsoft YaHei UI\";\n"
"}\n"
"\n"
"/* \351\274\240\346\240\207\346\202\254\345\201\234\346\227\266\347\232\204\351\200"
                        "\211\351\241\271\345\215\241\346\240\267\345\274\217 */\n"
"QTabBar::tab:hover \n"
"{\n"
"	border-color: rgb(85, 255, 127);\n"
"}\n"
"\n"
"/* \345\275\223\345\211\215\350\242\253\351\200\211\344\270\255\347\232\204\351\200\211\351\241\271\345\215\241\346\240\267\345\274\217 */\n"
"QTabBar::tab:selected \n"
"{\n"
"    border-bottom-color: transparent;  /* \351\200\211\344\270\255\346\227\266\347\247\273\351\231\244\345\272\225\351\203\250\350\276\271\346\241\206\344\273\245\350\247\206\350\247\211\350\236\215\345\220\210 */\n"
"}\n"
"\n"
""));
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 2, 0, 0);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        showWidget = new QWidget();
        showWidget->setObjectName("showWidget");
        picLb = new QLabel(showWidget);
        picLb->setObjectName("picLb");
        picLb->setGeometry(QRect(10, 10, 411, 401));
        picLb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 255);"));
        tabWidget->addTab(showWidget, QString());
        registerWidget = new RegisterWin();
        registerWidget->setObjectName("registerWidget");
        tabWidget->addTab(registerWidget, QString());
        selectWidget = new SelectWin();
        selectWidget->setObjectName("selectWidget");
        tabWidget->addTab(selectWidget, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        picLb->setText(QCoreApplication::translate("Widget", "\350\200\203\345\213\244\345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(showWidget), QCoreApplication::translate("Widget", "\350\200\203\345\213\244\345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(registerWidget), QCoreApplication::translate("Widget", "\346\263\250\345\206\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(selectWidget), QCoreApplication::translate("Widget", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QWidget *widgetlb;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_1;
    QLabel *lb_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *headpicLb;
    QLabel *videoLb;
    QWidget *widget_3;
    QLabel *headLb;
    QLabel *titleLb;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *employeeID;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *nickname;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *address;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *time;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 480);
        Widget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 480, 480));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widgetlb\n"
"{\n"
"	border-radius: 10px;\n"
"	background-color: rgba(180, 180, 180,0.8);\n"
"}\n"
"\n"
"QLabel#lb_1 \n"
"{\n"
"	border-image: url(:/images/yes.png);\n"
"}\n"
"\n"
"QLabel#lb_2 \n"
"{\n"
"	font: 25 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLabel#headpicLb\n"
"{\n"
"	border-image: url(:/images/crc.png);\n"
"}\n"
""));
        widgetlb = new QWidget(widget);
        widgetlb->setObjectName("widgetlb");
        widgetlb->setGeometry(QRect(90, 380, 271, 61));
        horizontalLayout_2 = new QHBoxLayout(widgetlb);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lb_1 = new QLabel(widgetlb);
        lb_1->setObjectName("lb_1");
        lb_1->setMinimumSize(QSize(31, 21));
        lb_1->setMaximumSize(QSize(31, 21));

        horizontalLayout->addWidget(lb_1);

        lb_2 = new QLabel(widgetlb);
        lb_2->setObjectName("lb_2");
        lb_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(lb_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        headpicLb = new QLabel(widget);
        headpicLb->setObjectName("headpicLb");
        headpicLb->setGeometry(QRect(100, 60, 266, 266));
        headpicLb->setScaledContents(true);
        videoLb = new QLabel(widget);
        videoLb->setObjectName("videoLb");
        videoLb->setGeometry(QRect(0, 0, 480, 480));
        videoLb->raise();
        widgetlb->raise();
        headpicLb->raise();
        widget_3 = new QWidget(Widget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(480, 0, 320, 480));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	border:1px solid #313236;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"}\n"
"\n"
"QLabel#titleLb\n"
"{\n"
"	font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLabel#headLb\n"
"{\n"
"	border-radius: 75px;\n"
"\n"
"}\n"
""));
        headLb = new QLabel(widget_3);
        headLb->setObjectName("headLb");
        headLb->setGeometry(QRect(90, 50, 150, 150));
        titleLb = new QLabel(widget_3);
        titleLb->setObjectName("titleLb");
        titleLb->setGeometry(QRect(0, 0, 320, 40));
        titleLb->setAlignment(Qt::AlignmentFlag::AlignCenter);
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 210, 271, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName("widget_4");
        widget_4->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	color: #00ffff;\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_4);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(6, 0, 0, -1);
        label_3 = new QLabel(widget_4);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        employeeID = new QLineEdit(widget_4);
        employeeID->setObjectName("employeeID");
        employeeID->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(employeeID->sizePolicy().hasHeightForWidth());
        employeeID->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(employeeID);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(layoutWidget);
        widget_5->setObjectName("widget_5");
        widget_5->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	color: #00ffff;\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_5);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(6, 0, 0, -1);
        label_4 = new QLabel(widget_5);
        label_4->setObjectName("label_4");

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        nickname = new QLineEdit(widget_5);
        nickname->setObjectName("nickname");
        nickname->setEnabled(false);
        sizePolicy.setHeightForWidth(nickname->sizePolicy().hasHeightForWidth());
        nickname->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(nickname);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(layoutWidget);
        widget_6->setObjectName("widget_6");
        widget_6->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	color: #00ffff;\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_6);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(6, 0, 0, -1);
        label_5 = new QLabel(widget_6);
        label_5->setObjectName("label_5");

        horizontalLayout_5->addWidget(label_5);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        address = new QLineEdit(widget_6);
        address->setObjectName("address");
        address->setEnabled(false);
        sizePolicy.setHeightForWidth(address->sizePolicy().hasHeightForWidth());
        address->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(address);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(layoutWidget);
        widget_7->setObjectName("widget_7");
        widget_7->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	border:none;\n"
"	color: #00ffff;\n"
"	\n"
"	font: 16pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border:none;\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"	font: 15pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        horizontalLayout_6 = new QHBoxLayout(widget_7);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(6, 0, 0, -1);
        label_6 = new QLabel(widget_7);
        label_6->setObjectName("label_6");

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        time = new QLineEdit(widget_7);
        time->setObjectName("time");
        time->setEnabled(false);
        sizePolicy.setHeightForWidth(time->sizePolicy().hasHeightForWidth());
        time->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(time);


        verticalLayout->addWidget(widget_7);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        lb_1->setText(QString());
        lb_2->setText(QCoreApplication::translate("Widget", "\350\256\244\350\257\201\346\210\220\345\212\237", nullptr));
        headpicLb->setText(QString());
        videoLb->setText(QString());
        headLb->setText(QString());
        titleLb->setText(QCoreApplication::translate("Widget", "\344\272\272\350\204\270\350\257\206\345\210\253\350\200\203\345\213\244\347\263\273\347\273\237", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\345\267\245\345\217\267", nullptr));
        employeeID->setText(QCoreApplication::translate("Widget", "001", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\247\223\345\220\215", nullptr));
        nickname->setText(QCoreApplication::translate("Widget", "zyh", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\351\203\250\351\227\250", nullptr));
        address->setText(QCoreApplication::translate("Widget", "\347\240\224\345\217\221", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264", nullptr));
        time->setText(QCoreApplication::translate("Widget", "2024-8-29", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

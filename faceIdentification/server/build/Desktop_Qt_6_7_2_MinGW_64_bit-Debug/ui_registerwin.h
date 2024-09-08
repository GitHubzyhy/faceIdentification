/********************************************************************************
** Form generated from reading UI file 'registerwin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIN_H
#define UI_REGISTERWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWin
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QRadioButton *mrb;
    QRadioButton *wrb;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QDateEdit *birthdayEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *registerBt;
    QPushButton *resetBt;
    QVBoxLayout *verticalLayout_2;
    QLabel *headpicLb;
    QLineEdit *picFileEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addpicBt;
    QPushButton *videoswitchBt;
    QPushButton *cameraBt;

    void setupUi(QWidget *RegisterWin)
    {
        if (RegisterWin->objectName().isEmpty())
            RegisterWin->setObjectName("RegisterWin");
        RegisterWin->resize(705, 427);
        RegisterWin->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(RegisterWin);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(RegisterWin);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget \n"
"{\n"
"	background-color: rgb(66, 74, 80);\n"
"}\n"
"\n"
"QLabel \n"
"{\n"
"	font-weight: bold;\n"
"	color: rgb(255, 255, 255);\n"
"	border: none;\n"
"}\n"
"\n"
"QRadioButton \n"
"{\n"
"	border: none;\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QRadioButton::indicator \n"
"{\n"
"	width: 13px;\n"
"	height: 13px;\n"
"	border-radius: 8px;\n"
"	border: 2px solid rgb(0, 255, 255);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked \n"
"{\n"
"	width: 13px;\n"
"	height: 13px;\n"
"	border-radius: 8px;\n"
"	background-color: rgb(0, 255, 255);\n"
"}\n"
"\n"
"QDateEdit \n"
"{\n"
"	border: 1px solid #404142;\n"
"	border-radius: 12px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"	font: 24pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"	border: 1px solid #404142;\n"
"	border-radius: 12px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"	font: 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"	color: rgb(255, 255"
                        ", 255);\n"
"}\n"
"\n"
"QLineEdit#picFileEdit\n"
"{\n"
"	width:313;\n"
"	height:35;\n"
"}\n"
"\n"
"QLineEdit:focus \n"
"{\n"
"	/* \345\275\223\350\242\253\351\200\211\344\270\255\346\227\266\357\274\214\350\276\271\346\241\206\351\242\234\350\211\262\344\270\272\350\223\235\350\211\262\357\274\214\344\270\224\345\212\240\347\262\227 */\n"
"	border: 2px solid #7b63e1;\n"
"}\n"
"\n"
"QPushButton \n"
"{\n"
"	color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(0, 255, 255);\n"
"	border-radius: 13px;\n"
"}\n"
"\n"
"QPushButton::hover \n"
"{\n"
"	background-color: rgb(0, 255, 255);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton::pressed \n"
"{\n"
"	/* \347\202\271\345\207\273\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	background-color: rgb(66, 74, 80);\n"
"	/* \347\202\271\345\207\273\346\227\266\347\232\204\350\276\271\346\241\206\351\242\234\350\211\262 */\n"
"	border: 1px solid rgb(0, 255, 127);\n"
"	\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
"QLabel#headpicLb \n"
""
                        "{\n"
"	background-image: url(:/images/photo.png);\n"
"	background-repeat: no-repeat;/* \351\230\262\346\255\242\345\233\276\347\211\207\351\207\215\345\244\215\346\230\276\347\244\272 */\n"
"	background-position: center;/* \345\233\276\347\211\207\345\261\205\344\270\255\346\230\276\347\244\272 */\n"
"}"));
        horizontalLayout_8 = new QHBoxLayout(widget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light")});
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(widget);
        nameEdit->setObjectName("nameEdit");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        nameEdit->setFont(font1);

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        mrb = new QRadioButton(widget);
        mrb->setObjectName("mrb");
        QFont font2;
        font2.setPointSize(15);
        mrb->setFont(font2);

        horizontalLayout_4->addWidget(mrb);

        wrb = new QRadioButton(widget);
        wrb->setObjectName("wrb");
        wrb->setFont(font2);

        horizontalLayout_4->addWidget(wrb);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_5->addWidget(label_6);

        birthdayEdit = new QDateEdit(widget);
        birthdayEdit->setObjectName("birthdayEdit");
        sizePolicy.setHeightForWidth(birthdayEdit->sizePolicy().hasHeightForWidth());
        birthdayEdit->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font3.setPointSize(24);
        font3.setBold(false);
        font3.setItalic(false);
        birthdayEdit->setFont(font3);

        horizontalLayout_5->addWidget(birthdayEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        addressEdit = new QLineEdit(widget);
        addressEdit->setObjectName("addressEdit");
        sizePolicy.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy);
        addressEdit->setFont(font1);

        horizontalLayout_2->addWidget(addressEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        phoneEdit = new QLineEdit(widget);
        phoneEdit->setObjectName("phoneEdit");
        sizePolicy.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy);
        phoneEdit->setFont(font1);

        horizontalLayout_3->addWidget(phoneEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        registerBt = new QPushButton(widget);
        registerBt->setObjectName("registerBt");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(registerBt->sizePolicy().hasHeightForWidth());
        registerBt->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(15);
        font4.setBold(false);
        registerBt->setFont(font4);

        horizontalLayout_6->addWidget(registerBt);

        resetBt = new QPushButton(widget);
        resetBt->setObjectName("resetBt");
        sizePolicy1.setHeightForWidth(resetBt->sizePolicy().hasHeightForWidth());
        resetBt->setSizePolicy(sizePolicy1);
        resetBt->setFont(font4);

        horizontalLayout_6->addWidget(resetBt);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        headpicLb = new QLabel(widget);
        headpicLb->setObjectName("headpicLb");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(headpicLb->sizePolicy().hasHeightForWidth());
        headpicLb->setSizePolicy(sizePolicy2);
        headpicLb->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(headpicLb);

        picFileEdit = new QLineEdit(widget);
        picFileEdit->setObjectName("picFileEdit");

        verticalLayout_2->addWidget(picFileEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        addpicBt = new QPushButton(widget);
        addpicBt->setObjectName("addpicBt");
        sizePolicy1.setHeightForWidth(addpicBt->sizePolicy().hasHeightForWidth());
        addpicBt->setSizePolicy(sizePolicy1);
        addpicBt->setFont(font4);

        horizontalLayout_7->addWidget(addpicBt);

        videoswitchBt = new QPushButton(widget);
        videoswitchBt->setObjectName("videoswitchBt");
        sizePolicy1.setHeightForWidth(videoswitchBt->sizePolicy().hasHeightForWidth());
        videoswitchBt->setSizePolicy(sizePolicy1);
        videoswitchBt->setFont(font4);

        horizontalLayout_7->addWidget(videoswitchBt);

        cameraBt = new QPushButton(widget);
        cameraBt->setObjectName("cameraBt");
        sizePolicy1.setHeightForWidth(cameraBt->sizePolicy().hasHeightForWidth());
        cameraBt->setSizePolicy(sizePolicy1);
        cameraBt->setFont(font4);

        horizontalLayout_7->addWidget(cameraBt);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_8->addLayout(verticalLayout_2);


        verticalLayout_3->addWidget(widget);


        retranslateUi(RegisterWin);

        QMetaObject::connectSlotsByName(RegisterWin);
    } // setupUi

    void retranslateUi(QWidget *RegisterWin)
    {
        RegisterWin->setWindowTitle(QCoreApplication::translate("RegisterWin", "Form", nullptr));
        label->setText(QCoreApplication::translate("RegisterWin", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWin", "\346\200\247\345\210\253\357\274\232", nullptr));
        mrb->setText(QCoreApplication::translate("RegisterWin", "\347\224\267", nullptr));
        wrb->setText(QCoreApplication::translate("RegisterWin", "\345\245\263", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterWin", "\347\224\237\346\227\245\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWin", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWin", "\347\224\265\350\257\235\357\274\232", nullptr));
        registerBt->setText(QCoreApplication::translate("RegisterWin", "\346\263\250\345\206\214", nullptr));
        resetBt->setText(QCoreApplication::translate("RegisterWin", "\351\207\215\347\275\256", nullptr));
        headpicLb->setText(QString());
        addpicBt->setText(QCoreApplication::translate("RegisterWin", "\346\267\273\345\212\240\345\244\264\345\203\217", nullptr));
        videoswitchBt->setText(QCoreApplication::translate("RegisterWin", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        cameraBt->setText(QCoreApplication::translate("RegisterWin", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWin: public Ui_RegisterWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIN_H

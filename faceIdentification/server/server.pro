QT       += core gui network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

win32
{
#添加头文件
INCLUDEPATH += D:\Environment\opencv452\include
INCLUDEPATH += D:\Environment\opencv452\include\opencv2
INCLUDEPATH += D:\Environment\SeetaFace2\include
INCLUDEPATH += D:\Environment\SeetaFace2\include\seeta

#添加添加库
LIBS += D:\Environment\opencv452\x64\mingw\lib\libopencv*
LIBS += D:\Environment\SeetaFace2\lib\libSeeta*
}

SOURCES += \
    main.cpp \
    qfaceobject.cpp \
    registerwin.cpp \
    selectwin.cpp \
    widget.cpp

HEADERS += \
    qfaceobject.h \
    registerwin.h \
    selectwin.h \
    widget.h

FORMS += \
    registerwin.ui \
    selectwin.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

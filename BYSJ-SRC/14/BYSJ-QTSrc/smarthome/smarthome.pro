#-------------------------------------------------
#
# Project created by QtCreator 2012-10-14T16:33:50
#
#-------------------------------------------------

QT       += core gui widgets network

TARGET = smarthome
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    homeform.cpp \
    nodemessage.cpp \
    comthread.cpp \
    wifithread.cpp \
    win_serial/win_qextserialport.cpp \
    win_serial/qextserialbase.cpp \
    setting.cpp \
    switchbutton.cpp


HEADERS  += widget.h \
    homeform.h \
    nodemessage.h \
    SensorData.h \
    comthread.h \
    win_serial/win_qextserialport.h \
    win_serial/qextserialbase.h \
    wifithread.h \
    setting.h \
    switchbutton.h


FORMS    += widget.ui \
    nodemessage.ui \
    homeform.ui \
    setting.ui

RESOURCES += \
    image.qrc
#INCLUDEPATH +="D:\Qt\Qt5.6.2\5.6\mingw49_32\include\QtNetwork"

DISTFILES +=

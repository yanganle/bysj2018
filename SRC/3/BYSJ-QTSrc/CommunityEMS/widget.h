#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPalette>
#include <QPixmap>
#include <QPushButton>
#include <QTextCodec>
#include "nodemessage.h"
#include "homeform.h"
#include "comthread.h"
#include "setting.h"
#include "switchbutton.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void setWidgetbackground(QWidget *widget,QPixmap image);
    void setButtonbackground(QPushButton *button,QPixmap picturepath);

    //void comportInit(comThread *&comport, Win_QextSerialPort *&myCom);
    ~Widget();

    double tempData;
    double humData;

private:
    Ui::Widget *ui;

    nodeMessage *nodeform;
    homeForm *navWidget;
    setting *setDialog;

    SwitchButton *modelbutton;

    comThread *comthread;
    WifiThread *wifithread;
    Win_QextSerialPort *com;
    QString comDev;


    QTimer *timer;
signals:

private slots:
    void InitComDev(int com);
    void InitWifiDev(void);
    void closeComthread(void);
    void closeWifithread(void);
    //void on_startButton_clicked();

    void recevicePM25data(double data);
    void receviceHumdata(double data);
    void receviceTempdata(double data);
};

#endif // WIDGET_H

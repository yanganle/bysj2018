#ifndef HOMEFORM_H
#define HOMEFORM_H

#include <QWidget>
#include <QPushButton>
#include <QList>
#include <QPalette>
#include <QPixmap>
#include <QDebug>
#include <QTextCodec>
#include <windows.h>
#include <QMovie>
#include <QTimer>
#include <qdatetime.h>
#include "SensorData.h"
#include "switchbutton.h"

namespace Ui {
    class homeForm;
}

class homeForm : public QWidget
{
    Q_OBJECT

public:
    explicit homeForm(QWidget *parent = 0);
    //void setWidgetbackground(QWidget *widget,QPixmap image);
    //void setButtonbackground(QPushButton *button,QPixmap picturepath);
    //void labelshow(int n,QPixmap pixmap);



    void updataValue(QByteArray sensorData);
    void SensorCtrolReq(quint8 sensortype, quint8 state);
    void SensorSetModelReq(quint8 model);
    void updateSensorStatus(quint8 sensortype);
    void resetSensorStatus();
    int getsensorConfig(quint8 netid,quint8 sensorType);
    ~homeForm();

private:
    Ui::homeForm *ui;
    SwitchButton *button1;
    SwitchButton *button2;

    QList <SensorRevData> SensorInfolist; //传感器数据链表
    SensorRevData *tempdata;
    //int listPosition[10];
    QTimer *timer;
    QTimer *timerdate;

    bool sensorflag0;
    bool sensorflag1;
    bool sensorflag2;
    bool sensorflag3;
    bool sensorflag4;

    quint8 tempThresholdValue;
    quint8 watlThresholdValue;

signals:
    void humancheck(bool flag);
    void tempcheck(double data);
    void humicheck(double data);
    void sensorCtrol(QByteArray sensorCmdData);

public slots:
    void reveiceData(QByteArray sensorData);
    void button1CheckHandle(bool buttonstate);
    void button2CheckHandle(bool buttonstate);
    bool saveDatatoList(QByteArray &sensorData);
    void changeStatus();
    void switchRunModle(bool modelflag);
    void timerUpdate(void);
private slots:
    void on_tempButton_clicked();
    void on_watlButton_clicked();
};

#endif // HOMEFORM_H

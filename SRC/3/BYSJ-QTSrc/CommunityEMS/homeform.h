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
    void updateSensorStatus(quint8 sensortype);
    void resetSensorStatus();
    int getsensorConfig(quint8 netid,quint8 sensorType);
    void runingSmartModel(QByteArray sensorData);
    ~homeForm();

private:
    Ui::homeForm *ui;
    SwitchButton *button1;
    SwitchButton *button2;

    QList <SensorRevData> SensorInfolist; //传感器数据链表
    SensorRevData *tempdata;
    //int listPosition[10];
    QTimer *timer;

    bool sensorflag0;
    bool sensorflag1;
    bool sensorflag2;
    bool sensorflag3;
    bool sensorflag4;

    int tempThresholdValue;
    int humiThresholdValue;
    int gasThresholdValue;
    int lightThresholdValue;

    bool runingModelFlag;
signals:
    void tempcheck(double value);
    void humicheck(double value);
    void pm25check(double value);
    void sensorCtrol(QByteArray sensorCmdData);

public slots:
    void reveiceData(QByteArray sensorData);
    void button2CheckHandle(bool buttonstate);
    bool saveDatatoList(QByteArray &sensorData);
    void changeStatus();
    void switchRunModle(bool modelflag);
private slots:
    void on_tempButton_clicked();
    void on_humiButton_clicked();
    void on_gasButton_clicked();
};

#endif // HOMEFORM_H

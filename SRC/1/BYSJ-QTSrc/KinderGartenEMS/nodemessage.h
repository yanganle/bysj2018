#ifndef NODEMESSAGE_H
#define NODEMESSAGE_H

#include <QMainWindow>
#include "SensorData.h"
#include <QList>
#include <QTableWidgetItem>
#include <QTimer>
namespace Ui {
    class nodeMessage;
}

class nodeMessage : public QMainWindow
{
    Q_OBJECT

public:
    explicit nodeMessage(QWidget *parent = 0);

    bool saveDatatoList(QByteArray &sensorData);
    void updataSensor(QByteArray sensorData);
    void recordLocation(int location);
    void writeStatus(int row,int column,bool status);


    ~nodeMessage();

private:
    Ui::nodeMessage *ui;
    QList <SensorRevData> SensorInfolist;
    SensorRevData *date;
    QTableWidgetItem *newItem;
    int listPosition[10];
    int listNum;
    QTimer *timer;

    bool atListfirstFlag;
    bool atListsecondFlag;
    bool atListthridFlag;

signals:
    void exitSender();
    void manCheck(bool flag);
    void smokeCheck(bool flag);
    void tempCheck(double data);
    void humCheck(double data);

private slots:
    void changeStatus();
    void on_back_triggered();
    void reveiceSensordata(QByteArray sensorData);
};

#endif // NODEMESSAGE_H

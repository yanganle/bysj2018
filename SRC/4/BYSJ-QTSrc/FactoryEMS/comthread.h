#ifndef COMTHREAD_H
#define COMTHREAD_H

#include <QThread>
#include "win_serial/win_qextserialport.h"
//#include "win_serial/posix_qextserialport.h"

class comThread : public QThread
{
    Q_OBJECT
public:
    explicit comThread(QObject *parent);
    //explicit comThread(Posix_QextSerialPort *com,int portno,QObject *parent);
    void ReceiveData();
    bool comInit(QString com);
    virtual void run();
private:
    Win_QextSerialPort *comPort;//要接受的串口
    //Posix_QextSerialPort *threadcom;
    QByteArray sensormessage;
    QString comNo;
signals:
    void sensorData(QByteArray);
    void comStatesender(bool flag);
public slots:
    void comClose();
    void SendComData(QByteArray msg);
};

#endif // COMTHREAD_H

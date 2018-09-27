#ifndef WIFITHREAD_H
#define WIFITHREAD_H

#include <QWidget>
#include <QUdpSocket>
#include <QHostAddress>
#include <SensorData.h>
#include <QThread>

class WifiThread : public QThread
{
    Q_OBJECT
public:
    explicit WifiThread(QObject *parent);
    bool SocketInit();
    virtual void run();
private:
    QUdpSocket *udpSocket;
    //SensorRevData *templistinfo;

    QHostAddress socketSender;
    quint16 senderPort;

signals:
    void sensorWifiData(QByteArray);
    void wifiStatesender(bool flag);

public slots:
    //void setOpen();
    void wifiClose();
    void readPendingDatagrams();
    void SendWifiData(QByteArray msg);
};

#endif // WIFITHREAD_H

#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QTextCodec>
#include "comthread.h"
#include "wifithread.h"
#include "nodemessage.h"
#include "homeform.h"

#define DEVWIFI 0xAA
#define DEVUART 0xBB

namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    ~setting();

    void changeConnectstate(bool flag);

private:
    Ui::setting *ui;

    QStringList ComList;
    bool buttonState;
    unsigned char devState;

signals:
    void comInitsender(int com);
    void wifiInitsender();
    void comClosesender();
    void wifiClosesender();

private slots:
    void setComstate(bool flag);
    void on_wifiButton_clicked();
    void on_uartButton_clicked();
    void on_connectButton_clicked();
};

#endif // SETTING_H

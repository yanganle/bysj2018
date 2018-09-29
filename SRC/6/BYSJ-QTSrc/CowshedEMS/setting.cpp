#include "setting.h"
#include "ui_setting.h"
#include "win_serial/qextserialbase.h"

setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    ui->setupUi(this);
    this->hide();
    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForLocale(codec);
    this->setWindowTitle(QString::fromLocal8Bit("设置"));
    this->setWindowOpacity(0.9); //背景和元素都设置透明效果
    this->setModal(true); //设置为模态界面

    devState = 0;
    ComList<< "COM1" << "COM2" << "COM3" << "COM4" << "COM5" << "COM6" << "COM7" << "COM8";
    for(int i=0;i<ComList.size();i++)
        ui->comboBox->addItem(ComList.at(i));
}

setting::~setting()
{
    delete ui;
}

void setting::setComstate(bool flag)
{
    if(flag)
    {
        changeConnectstate(true);
    }
    else
    {
        changeConnectstate(false);
    }

}

void setting::changeConnectstate(bool flag)
{
    if(devState == DEVWIFI) //wifi设备
    {
        if(flag)
        {
            ui->connectWifiState->setText(QString::fromLocal8Bit("连接成功!"));
            //timer->start(3000);
            ui->connectButton->setText(QString::fromLocal8Bit("断开"));
            buttonState = true;
        }
        else
        {
            ui->connectWifiState->setText(QString::fromLocal8Bit("连接失败..."));
            ui->connectButton->setText(QString::fromLocal8Bit("连接"));
            buttonState = false;
        }
    }else if(devState == DEVUART) //串口设备
    {
        if(flag)
        {
            ui->connectComState->setText(QString::fromLocal8Bit("连接成功!"));
            //timer->start(3000);
            ui->connectButton->setText(QString::fromLocal8Bit("断开"));
            buttonState = true;
        }
        else
        {
            ui->connectComState->setText(QString::fromLocal8Bit("连接失败..."));
            ui->connectButton->setText(QString::fromLocal8Bit("连接"));
            buttonState = false;
        }
    }
}

void setting::on_wifiButton_clicked()
{
    qDebug()<<"DEVWIFI";
    devState = DEVWIFI;
}

void setting::on_uartButton_clicked()
{
    qDebug()<<"DEVUART";
    devState = DEVUART;
}

void setting::on_connectButton_clicked()
{
    if(devState == DEVWIFI) //wifi设备
    {
        qDebug()<<"CHANG DEVWIFI";
        emit comClosesender(); //打开WiFi之前关闭串口

        if(!buttonState)
        {
            emit wifiInitsender();
        }
        else
        {
            emit wifiClosesender();
            ui->connectButton->setText(QString::fromLocal8Bit("连接"));
            ui->connectWifiState->setText(QString::fromLocal8Bit("连接失败..."));
            buttonState = false;
        }
    }
    else if(devState == DEVUART)//串口设备
    {
        qDebug()<<"CHANG DEVUART";

        emit wifiClosesender(); //打开串口之前关闭wifi
        if(!buttonState)
        {
            qDebug()<<"SET START DEVUART";
            emit comInitsender(ui->comboBox->currentIndex()); //发送com消息
        }
        else
        {
            emit comClosesender();
            ui->connectButton->setText(QString::fromLocal8Bit("连接"));
            ui->connectComState->setText(QString::fromLocal8Bit("未连接..."));
            buttonState = false;
        }
    }else
    {
        ui->connectButton->setText(QString::fromLocal8Bit("连接"));
    }
}

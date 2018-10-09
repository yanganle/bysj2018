#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QTextCodec *codec = QTextCodec::codecForName("utf8"); //GBK gbk
    QTextCodec::setCodecForLocale(codec);

    this->setWindowTitle(QString::fromLocal8Bit("车辆防盗系统"));

    setWidgetbackground(this,QPixmap(":/rcs/mainpage.jpg"));
    //setButtonbackground(ui->startButton,QPixmap(":/rcs/widgetButton.png"));
    setButtonbackground(ui->navButton,QPixmap(":/rcs/homeButton.png"));
    setButtonbackground(ui->setButton,QPixmap(":/rcs/setButton.png"));

    //模式选择开关
    modelbutton = new SwitchButton(this);
    modelbutton->setText(QString::fromLocal8Bit("智能"),QString::fromLocal8Bit("普通"));
    modelbutton->setGeometry(rect().x()+255, rect().y()+210,65, 26);
    modelbutton->setParent(this);

    comDev = "COM2";
    comthread = NULL;
    wifithread = NULL;

    nodeform = new nodeMessage();
    navWidget = new homeForm();
    setDialog = new setting();

    connect(ui->navButton,SIGNAL(clicked()),navWidget,SLOT(show()));
    connect(ui->setButton,SIGNAL(clicked()),setDialog,SLOT(show()));

    //串口相关
    connect(setDialog,SIGNAL(comInitsender(int)),this,SLOT(InitComDev(int)));
    connect(modelbutton,SIGNAL(checkedChanged(bool)),navWidget,SLOT(switchRunModle(bool)));

    connect(navWidget,SIGNAL(humicheck(bool)),this,SLOT(receviceHumdata(bool)));
    connect(navWidget,SIGNAL(tempcheck(bool)),this,SLOT(receviceTempdata(bool)));
    connect(navWidget,SIGNAL(humancheck(bool)),this,SLOT(receviceMandata(bool)));
}
Widget::~Widget()
{
    delete ui;
}

void Widget::InitComDev(int com)
{
    qDebug()<<com;
    switch(com)
    {
        case 0: comDev = "COM1";
                break;
        case 1: comDev = "COM2";
                break;
        case 2: comDev = "COM3";
                break;
        case 3: comDev = "COM4";
                break;
        case 4: comDev = "COM5";
                break;
        case 5: comDev = "COM6";
                break;
        case 6: comDev = "COM7";
                break;
        case 7: comDev = "COM8";
                break;
        default:
                break;

    }
    if(comthread!=NULL)
    {
        comthread->quit();
    }
    comthread = new comThread(this);
    connect(comthread,SIGNAL(comStatesender(bool)),setDialog,SLOT(setComstate(bool)));
    if(comthread->comInit(comDev))
    {
        //把从线程里接受的数据发送到节点信息窗口
        connect(comthread,SIGNAL(sensorData(QByteArray)),navWidget,SLOT(reveiceData(QByteArray)));
        connect(navWidget,SIGNAL(sensorCtrol(QByteArray)),comthread,SLOT(SendComData(QByteArray)));
        connect(setDialog,SIGNAL(comClosesender()),comthread,SLOT(comClose()));
        connect(setDialog,SIGNAL(comClosesender()),this,SLOT(closeComthread()));
        comthread->start(); //开启线程
    }
}

void Widget::InitWifiDev(void)
{
    if(wifithread != NULL)
    {
        wifithread->quit();
    }
    wifithread = new WifiThread(this);
    connect(wifithread,SIGNAL(wifiStatesender(bool)),setDialog,SLOT(setComstate(bool)));
    if(wifithread->SocketInit())
    {
        qDebug()<<"start thread";
        //把从线程里接受的数据发送到节点信息窗口
        connect(wifithread,SIGNAL(sensorWifiData(QByteArray)),navWidget,SLOT(reveiceData(QByteArray)));
        connect(setDialog,SIGNAL(wifiClosesender()),this,SLOT(closeWifithread()));
        wifithread->start(); //开启线程
    }
}

void Widget::closeComthread(void)
{
    comthread->terminate(); //关闭线程
}
void Widget::closeWifithread(void)
{
    wifithread->terminate(); //关闭线程
}

//设置窗体背景
void Widget::setWidgetbackground(QWidget *widget,QPixmap image)
{
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(image));
    widget->setPalette(palette);
}

//设置按钮背景
void Widget::setButtonbackground(QPushButton *button,QPixmap picturepath)
{
    button->setFixedSize(picturepath.width(),picturepath.height());
    button->setIcon(QIcon(picturepath));
    button->setFlat(true);
    button->setIconSize(QSize(picturepath.width(),picturepath.height()));
    button->setToolTip("");
}

void Widget::receviceMandata(bool flag)
{
    if(flag)
    {
        ui->manLabel->setText(QString::fromLocal8Bit("有人"));
    }else
    {
        ui->manLabel->setText(QString::fromLocal8Bit("无人"));
    }
}

void Widget::receviceTempdata(bool flag)
{
    if(flag)
    {
        ui->shakeLabel->setText(QString::fromLocal8Bit("震动"));
    }else
    {
        ui->shakeLabel->setText(QString::fromLocal8Bit("静止"));
    }
}
void Widget::receviceHumdata(bool flag)
{
    if(flag)
    {
        ui->alarmLabel->setText(QString::fromLocal8Bit("工作中"));
    }else
    {
        ui->alarmLabel->setText(QString::fromLocal8Bit("未工作"));
    }
}
void Widget::on_startButton_clicked()
{
    //nodeform->show();
}


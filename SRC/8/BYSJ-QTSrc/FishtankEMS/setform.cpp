#include "setform.h"
#include "ui_setform.h"
#include <QDebug>


setForm::setForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setForm)
{
    ui->setupUi(this);
    //setWidgetbackground(this,QPixmap(":/rcs/setbackground.jpg"));
    ComList<< "COM1" << "COM2" << "COM3" << "COM4" << "COM5" << "COM6" << "COM7" << "COM8";

    for(int i=0;i<ComList.size();i++)
    {
        ui->comboBox->addItem(ComList.at(i));
    }
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(hide()));
    hide();

}

setForm::~setForm()
{
    delete ui;
}

void setForm::on_pushButton_clicked()
{
    if(!buttonState)
    {
        emit comNosender(ui->comboBox->currentIndex());
        //buttonState = true;
    }
    else
    {
        emit comClosesender();
        ui->pushButton->setText("����");
        ui->connectState->setText("����ʧ��...");
        buttonState = false;
    }

}
void setForm::changeConnectstate(bool flag)
{
    if(flag)
    {
        ui->connectState->setText("���ӳɹ�!");
        //timer->start(3000);
        ui->pushButton->setText("�Ͽ�");
        buttonState = true;
    }
    else
    {
        ui->connectState->setText("����ʧ��...");
        ui->pushButton->setText("����");
        buttonState = false;
    }
}

void setForm::setWidgetbackground(QWidget *widget,QPixmap image)
{
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(image));
    widget->setPalette(palette);
}

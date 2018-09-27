#ifndef SETFORM_H
#define SETFORM_H

#include <QWidget>
#include <QTimer>

namespace Ui {
    class setForm;
}

class setForm : public QWidget
{
    Q_OBJECT

public:
    explicit setForm(QWidget *parent = 0);
    void changeConnectstate(bool flag);
    void setWidgetbackground(QWidget *widget,QPixmap image);
    ~setForm();

private:
    Ui::setForm *ui;
    QStringList ComList;
    QTimer *timer;
    bool buttonState;

signals:
    void comNosender(int num);
    void comClosesender();
private slots:
    void on_pushButton_clicked();
};

#endif // SETFORM_H

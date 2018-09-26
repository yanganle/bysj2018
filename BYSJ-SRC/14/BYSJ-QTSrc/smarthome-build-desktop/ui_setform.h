/********************************************************************************
** Form generated from reading UI file 'setform.ui'
**
** Created: Mon Oct 15 13:11:44 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETFORM_H
#define UI_SETFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setForm
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *connectState;
    QPushButton *pushButton;

    void setupUi(QWidget *setForm)
    {
        if (setForm->objectName().isEmpty())
            setForm->setObjectName(QString::fromUtf8("setForm"));
        setForm->resize(388, 141);
        setForm->setWindowOpacity(1);
        setForm->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(setForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 10, 101, 31));
        label->setStyleSheet(QString::fromUtf8("background-image: url();"));
        label_2 = new QLabel(setForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 70, 81, 41));
        label_2->setStyleSheet(QString::fromUtf8("background-image: url();"));
        comboBox = new QComboBox(setForm);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(120, 80, 71, 21));
        connectState = new QLabel(setForm);
        connectState->setObjectName(QString::fromUtf8("connectState"));
        connectState->setGeometry(QRect(300, 80, 71, 21));
        connectState->setStyleSheet(QString::fromUtf8("background-image: url();"));
        pushButton = new QPushButton(setForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 80, 71, 21));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url();"));

        retranslateUi(setForm);

        QMetaObject::connectSlotsByName(setForm);
    } // setupUi

    void retranslateUi(QWidget *setForm)
    {
        setForm->setWindowTitle(QApplication::translate("setForm", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("setForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600; font-style:italic;\">\344\270\262\345\217\243\351\205\215\347\275\256</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("setForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">\344\270\262\345\217\243\350\256\276\345\244\207:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        connectState->setText(QApplication::translate("setForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\346\234\252\350\277\236\346\216\245....</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("setForm", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class setForm: public Ui_setForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETFORM_H

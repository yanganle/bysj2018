/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QDialogButtonBox *buttonBox;
    QRadioButton *wifiButton;
    QRadioButton *uartButton;
    QComboBox *comboBox;
    QLabel *connectWifiState;
    QLabel *connectComState;
    QPushButton *connectButton;

    void setupUi(QDialog *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QStringLiteral("setting"));
        setting->resize(400, 300);
        buttonBox = new QDialogButtonBox(setting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(220, 250, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        wifiButton = new QRadioButton(setting);
        wifiButton->setObjectName(QStringLiteral("wifiButton"));
        wifiButton->setGeometry(QRect(70, 80, 161, 41));
        wifiButton->setStyleSheet(QLatin1String("color: rgb(21, 185, 255);\n"
"font: 24pt \"18thCentury\";"));
        wifiButton->setIconSize(QSize(25, 25));
        uartButton = new QRadioButton(setting);
        uartButton->setObjectName(QStringLiteral("uartButton"));
        uartButton->setGeometry(QRect(70, 150, 151, 31));
        uartButton->setStyleSheet(QLatin1String("color: rgb(223, 220, 255);\n"
"color: rgb(21, 185, 255);\n"
"font: 24pt \"18thCentury\";"));
        comboBox = new QComboBox(setting);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(20, 250, 81, 22));
        connectWifiState = new QLabel(setting);
        connectWifiState->setObjectName(QStringLiteral("connectWifiState"));
        connectWifiState->setGeometry(QRect(240, 90, 101, 31));
        connectWifiState->setStyleSheet(QLatin1String("font: 18pt \"18thCentury\";\n"
"color: rgb(255, 0, 0);"));
        connectComState = new QLabel(setting);
        connectComState->setObjectName(QStringLiteral("connectComState"));
        connectComState->setGeometry(QRect(230, 150, 101, 31));
        connectComState->setStyleSheet(QLatin1String("font: 18pt \"18thCentury\";\n"
"color: rgb(255, 0, 0);"));
        connectButton = new QPushButton(setting);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(110, 250, 75, 23));

        retranslateUi(setting);
        QObject::connect(buttonBox, SIGNAL(accepted()), setting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), setting, SLOT(reject()));

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QDialog *setting)
    {
        setting->setWindowTitle(QApplication::translate("setting", "Dialog", 0));
        wifiButton->setText(QApplication::translate("setting", "WIFI \350\256\276\345\244\207", 0));
        uartButton->setText(QApplication::translate("setting", "\344\270\262\345\217\243\350\256\276\345\244\207", 0));
        connectWifiState->setText(QApplication::translate("setting", "\346\234\252\350\277\236\346\216\245 . . .", 0));
        connectComState->setText(QApplication::translate("setting", "\346\234\252\350\277\236\346\216\245 . . .", 0));
        connectButton->setText(QApplication::translate("setting", "\350\277\236\346\216\245", 0));
    } // retranslateUi

};

namespace Ui {
    class setting: public Ui_setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H

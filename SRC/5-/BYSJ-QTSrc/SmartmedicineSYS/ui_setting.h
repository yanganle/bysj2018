/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setting
{
public:
    QRadioButton *wifiButton;
    QRadioButton *uartButton;
    QLabel *connectWifiState;
    QLabel *connectComState;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *setting)
    {
        if (setting->objectName().isEmpty())
            setting->setObjectName(QStringLiteral("setting"));
        setting->resize(356, 208);
        wifiButton = new QRadioButton(setting);
        wifiButton->setObjectName(QStringLiteral("wifiButton"));
        wifiButton->setGeometry(QRect(60, 33, 121, 41));
        QFont font;
        font.setPointSize(17);
        wifiButton->setFont(font);
        wifiButton->setStyleSheet(QStringLiteral(""));
        wifiButton->setIconSize(QSize(25, 25));
        uartButton = new QRadioButton(setting);
        uartButton->setObjectName(QStringLiteral("uartButton"));
        uartButton->setGeometry(QRect(60, 90, 121, 31));
        uartButton->setFont(font);
        uartButton->setStyleSheet(QStringLiteral(""));
        connectWifiState = new QLabel(setting);
        connectWifiState->setObjectName(QStringLiteral("connectWifiState"));
        connectWifiState->setGeometry(QRect(190, 40, 101, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("18thCentury"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        connectWifiState->setFont(font1);
        connectWifiState->setStyleSheet(QLatin1String("font: 18pt \"18thCentury\";\n"
"color: rgb(255, 0, 0);"));
        connectComState = new QLabel(setting);
        connectComState->setObjectName(QStringLiteral("connectComState"));
        connectComState->setGeometry(QRect(190, 90, 101, 31));
        connectComState->setStyleSheet(QLatin1String("font: 18pt \"18thCentury\";\n"
"color: rgb(255, 0, 0);"));
        widget = new QWidget(setting);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 160, 333, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);

        connectButton = new QPushButton(widget);
        connectButton->setObjectName(QStringLiteral("connectButton"));

        horizontalLayout->addWidget(connectButton);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(setting);
        QObject::connect(buttonBox, SIGNAL(accepted()), setting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), setting, SLOT(reject()));

        QMetaObject::connectSlotsByName(setting);
    } // setupUi

    void retranslateUi(QDialog *setting)
    {
        setting->setWindowTitle(QApplication::translate("setting", "Dialog", 0));
        wifiButton->setText(QApplication::translate("setting", "WIFI\350\256\276\345\244\207", 0));
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

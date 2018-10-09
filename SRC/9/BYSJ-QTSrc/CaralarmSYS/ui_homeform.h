/********************************************************************************
** Form generated from reading UI file 'homeform.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEFORM_H
#define UI_HOMEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homeForm
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QFrame *line;
    QPushButton *tempButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *manStatelabel;
    QLabel *label_30;
    QLabel *manpixlabel;
    QGroupBox *groupBox_4;
    QFrame *line_6;
    QLabel *nonepixlabel;
    QLabel *label_39;
    QLabel *noneStatelabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *label_26;
    QGroupBox *groupBox_6;
    QFrame *line_4;
    QLabel *label_35;
    QLabel *pumpStatelabel;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_16;
    QLabel *label_15;
    QLabel *label_13;
    QLabel *pumpvaluelabel;
    QLabel *pumppixlabel;
    QGroupBox *groupBox_3;
    QFrame *line_5;
    QLabel *turbpixlabel;
    QLabel *label_37;
    QLabel *turbStatelabel;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *turbvaluelabel;
    QGroupBox *groupBox_5;
    QFrame *line_3;
    QLabel *label_33;
    QLabel *alarmStatelabel;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_36;
    QLabel *lampvaluelabel;
    QLabel *alarmpixlabel;
    QGroupBox *groupBox_2;
    QFrame *line_2;
    QPushButton *watlButton;
    QLabel *label_31;
    QLabel *shakeStatelabel;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *shakepixlabel;

    void setupUi(QWidget *homeForm)
    {
        if (homeForm->objectName().isEmpty())
            homeForm->setObjectName(QStringLiteral("homeForm"));
        homeForm->resize(800, 480);
        homeForm->setMaximumSize(QSize(800, 480));
        homeForm->setAutoFillBackground(true);
        gridLayout = new QGridLayout(homeForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(homeForm);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMinimumSize(QSize(100, 50));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 460));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(220, 20, 20, 101));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        tempButton = new QPushButton(groupBox);
        tempButton->setObjectName(QStringLiteral("tempButton"));
        tempButton->setGeometry(QRect(300, 100, 61, 23));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(240, 30, 62, 91));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        manStatelabel = new QLabel(groupBox);
        manStatelabel->setObjectName(QStringLiteral("manStatelabel"));
        manStatelabel->setGeometry(QRect(320, 35, 31, 16));
        label_30 = new QLabel(groupBox);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(320, 70, 31, 16));
        manpixlabel = new QLabel(groupBox);
        manpixlabel->setObjectName(QStringLiteral("manpixlabel"));
        manpixlabel->setGeometry(QRect(60, 30, 81, 81));

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        line_6 = new QFrame(groupBox_4);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(220, 20, 20, 101));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        nonepixlabel = new QLabel(groupBox_4);
        nonepixlabel->setObjectName(QStringLiteral("nonepixlabel"));
        nonepixlabel->setGeometry(QRect(80, 30, 81, 81));
        label_39 = new QLabel(groupBox_4);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(320, 65, 31, 16));
        noneStatelabel = new QLabel(groupBox_4);
        noneStatelabel->setObjectName(QStringLiteral("noneStatelabel"));
        noneStatelabel->setGeometry(QRect(320, 30, 31, 21));
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 27, 62, 91));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_25 = new QLabel(layoutWidget1);
        label_25->setObjectName(QStringLiteral("label_25"));

        verticalLayout_6->addWidget(label_25);

        label_24 = new QLabel(layoutWidget1);
        label_24->setObjectName(QStringLiteral("label_24"));

        verticalLayout_6->addWidget(label_24);

        label_26 = new QLabel(layoutWidget1);
        label_26->setObjectName(QStringLiteral("label_26"));

        verticalLayout_6->addWidget(label_26);


        gridLayout_2->addWidget(groupBox_4, 2, 1, 1, 1);

        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        line_4 = new QFrame(groupBox_6);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(220, 20, 20, 101));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        label_35 = new QLabel(groupBox_6);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(320, 70, 31, 16));
        pumpStatelabel = new QLabel(groupBox_6);
        pumpStatelabel->setObjectName(QStringLiteral("pumpStatelabel"));
        pumpStatelabel->setGeometry(QRect(320, 35, 31, 16));
        layoutWidget2 = new QWidget(groupBox_6);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(240, 30, 62, 91));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget2);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_4->addWidget(label_16);

        label_15 = new QLabel(layoutWidget2);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_4->addWidget(label_15);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_4->addWidget(label_13);

        pumpvaluelabel = new QLabel(groupBox_6);
        pumpvaluelabel->setObjectName(QStringLiteral("pumpvaluelabel"));
        pumpvaluelabel->setGeometry(QRect(170, 70, 41, 21));
        pumppixlabel = new QLabel(groupBox_6);
        pumppixlabel->setObjectName(QStringLiteral("pumppixlabel"));
        pumppixlabel->setGeometry(QRect(70, 40, 81, 81));

        gridLayout_2->addWidget(groupBox_6, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        line_5 = new QFrame(groupBox_3);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(220, 20, 20, 101));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);
        turbpixlabel = new QLabel(groupBox_3);
        turbpixlabel->setObjectName(QStringLiteral("turbpixlabel"));
        turbpixlabel->setGeometry(QRect(80, 40, 81, 81));
        label_37 = new QLabel(groupBox_3);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(320, 70, 31, 16));
        turbStatelabel = new QLabel(groupBox_3);
        turbStatelabel->setObjectName(QStringLiteral("turbStatelabel"));
        turbStatelabel->setGeometry(QRect(320, 35, 31, 16));
        layoutWidget3 = new QWidget(groupBox_3);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(240, 30, 62, 91));
        verticalLayout_5 = new QVBoxLayout(layoutWidget3);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget3);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_5->addWidget(label_21);

        label_22 = new QLabel(layoutWidget3);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_5->addWidget(label_22);

        label_23 = new QLabel(layoutWidget3);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_5->addWidget(label_23);

        turbvaluelabel = new QLabel(groupBox_3);
        turbvaluelabel->setObjectName(QStringLiteral("turbvaluelabel"));
        turbvaluelabel->setGeometry(QRect(170, 70, 41, 21));

        gridLayout_2->addWidget(groupBox_3, 2, 0, 1, 1);

        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        line_3 = new QFrame(groupBox_5);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(220, 20, 20, 101));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_33 = new QLabel(groupBox_5);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(320, 70, 31, 16));
        alarmStatelabel = new QLabel(groupBox_5);
        alarmStatelabel->setObjectName(QStringLiteral("alarmStatelabel"));
        alarmStatelabel->setGeometry(QRect(320, 35, 31, 16));
        layoutWidget4 = new QWidget(groupBox_5);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(240, 30, 62, 91));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget4);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_3->addWidget(label_12);

        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);

        label_9 = new QLabel(layoutWidget4);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_3->addWidget(label_9);

        label_36 = new QLabel(groupBox_5);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(320, 70, 31, 16));
        lampvaluelabel = new QLabel(groupBox_5);
        lampvaluelabel->setObjectName(QStringLiteral("lampvaluelabel"));
        lampvaluelabel->setGeometry(QRect(170, 70, 41, 21));
        alarmpixlabel = new QLabel(groupBox_5);
        alarmpixlabel->setObjectName(QStringLiteral("alarmpixlabel"));
        alarmpixlabel->setGeometry(QRect(60, 40, 81, 81));

        gridLayout_2->addWidget(groupBox_5, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(220, 20, 20, 101));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        watlButton = new QPushButton(groupBox_2);
        watlButton->setObjectName(QStringLiteral("watlButton"));
        watlButton->setGeometry(QRect(300, 100, 61, 23));
        label_31 = new QLabel(groupBox_2);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(320, 70, 31, 16));
        shakeStatelabel = new QLabel(groupBox_2);
        shakeStatelabel->setObjectName(QStringLiteral("shakeStatelabel"));
        shakeStatelabel->setGeometry(QRect(320, 35, 35, 16));
        layoutWidget5 = new QWidget(groupBox_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(240, 30, 62, 91));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget5);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_7 = new QLabel(layoutWidget5);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_5 = new QLabel(layoutWidget5);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        shakepixlabel = new QLabel(groupBox_2);
        shakepixlabel->setObjectName(QStringLiteral("shakepixlabel"));
        shakepixlabel->setGeometry(QRect(80, 30, 81, 81));

        gridLayout_2->addWidget(groupBox_2, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 1, 1, 1);


        retranslateUi(homeForm);

        QMetaObject::connectSlotsByName(homeForm);
    } // setupUi

    void retranslateUi(QWidget *homeForm)
    {
        homeForm->setWindowTitle(QApplication::translate("homeForm", "Form", 0));
        groupBox->setTitle(QApplication::translate("homeForm", "\344\272\272\344\275\223", 0));
        tempButton->setText(QApplication::translate("homeForm", "\347\241\256\345\256\232", 0));
        label->setText(QApplication::translate("homeForm", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", 0));
        label_2->setText(QApplication::translate("homeForm", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", 0));
        label_3->setText(QApplication::translate("homeForm", "\351\230\210\345\200\274\350\256\276\347\275\256", 0));
        manStatelabel->setText(QApplication::translate("homeForm", "\347\246\273\347\272\277", 0));
        label_30->setText(QApplication::translate("homeForm", "\346\243\200\346\265\213", 0));
        manpixlabel->setText(QString());
        groupBox_4->setTitle(QString());
        nonepixlabel->setText(QString());
        label_39->setText(QString());
        noneStatelabel->setText(QString());
        label_25->setText(QString());
        label_24->setText(QString());
        label_26->setText(QString());
        groupBox_6->setTitle(QString());
        label_35->setText(QString());
        pumpStatelabel->setText(QString());
        label_16->setText(QString());
        label_15->setText(QString());
        label_13->setText(QString());
        pumpvaluelabel->setText(QString());
        pumppixlabel->setText(QString());
        groupBox_3->setTitle(QString());
        turbpixlabel->setText(QString());
        label_37->setText(QString());
        turbStatelabel->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        turbvaluelabel->setText(QString());
        groupBox_5->setTitle(QApplication::translate("homeForm", "\346\212\245\350\255\246", 0));
        label_33->setText(QString());
        alarmStatelabel->setText(QApplication::translate("homeForm", "\347\246\273\347\272\277", 0));
        label_12->setText(QApplication::translate("homeForm", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", 0));
        label_11->setText(QApplication::translate("homeForm", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", 0));
        label_9->setText(QApplication::translate("homeForm", "\351\230\210\345\200\274\350\256\276\347\275\256", 0));
        label_36->setText(QApplication::translate("homeForm", "\346\216\247\345\210\266", 0));
        lampvaluelabel->setText(QString());
        alarmpixlabel->setText(QString());
        groupBox_2->setTitle(QApplication::translate("homeForm", "\351\234\207\345\212\250", 0));
        watlButton->setText(QApplication::translate("homeForm", "\347\241\256\345\256\232", 0));
        label_31->setText(QApplication::translate("homeForm", "\346\243\200\346\265\213", 0));
        shakeStatelabel->setText(QApplication::translate("homeForm", "\347\246\273\347\272\277", 0));
        label_8->setText(QApplication::translate("homeForm", "\350\256\276\345\244\207\347\212\266\346\200\201\357\274\232", 0));
        label_7->setText(QApplication::translate("homeForm", "\350\256\276\345\244\207\347\261\273\345\236\213\357\274\232", 0));
        label_5->setText(QApplication::translate("homeForm", "\351\230\210\345\200\274\350\256\276\347\275\256", 0));
        shakepixlabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class homeForm: public Ui_homeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEFORM_H

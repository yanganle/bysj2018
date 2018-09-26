/********************************************************************************
** Form generated from reading UI file 'homeform.ui'
**
** Created: Mon Oct 15 13:26:02 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEFORM_H
#define UI_HOMEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_homeForm
{
public:
    QPushButton *backButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QProgressBar *humProgressBar;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QProgressBar *tempProgressBar;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *humLabel;
    QLabel *label_8;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLabel *tempLabel;
    QLabel *label_10;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_3;
    QLabel *manlabel;
    QLabel *label_11;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_4;
    QLabel *smokelabel;
    QLabel *label_12;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_5;
    QLabel *templabel;
    QLabel *label_13;

    void setupUi(QWidget *homeForm)
    {
        if (homeForm->objectName().isEmpty())
            homeForm->setObjectName(QString::fromUtf8("homeForm"));
        homeForm->resize(800, 480);
        homeForm->setMaximumSize(QSize(800, 480));
        homeForm->setAutoFillBackground(true);
        backButton = new QPushButton(homeForm);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(700, 410, 71, 51));
        layoutWidget = new QWidget(homeForm);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(350, 140, 62, 96));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        humProgressBar = new QProgressBar(layoutWidget);
        humProgressBar->setObjectName(QString::fromUtf8("humProgressBar"));
        humProgressBar->setEnabled(true);
        humProgressBar->setValue(0);
        humProgressBar->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(humProgressBar);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        layoutWidget1 = new QWidget(homeForm);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(450, 140, 71, 96));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tempProgressBar = new QProgressBar(layoutWidget1);
        tempProgressBar->setObjectName(QString::fromUtf8("tempProgressBar"));
        tempProgressBar->setValue(0);
        tempProgressBar->setOrientation(Qt::Vertical);

        horizontalLayout_2->addWidget(tempProgressBar);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_2->addWidget(label_6);


        horizontalLayout_2->addLayout(verticalLayout_2);

        layoutWidget2 = new QWidget(homeForm);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(300, 240, 91, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        humLabel = new QLabel(layoutWidget2);
        humLabel->setObjectName(QString::fromUtf8("humLabel"));
        humLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

        horizontalLayout_3->addWidget(humLabel);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_3->addWidget(label_8);

        horizontalLayout_3->setStretch(1, 4);
        horizontalLayout_3->setStretch(2, 1);
        layoutWidget3 = new QWidget(homeForm);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(410, 240, 101, 21));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget3);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        tempLabel = new QLabel(layoutWidget3);
        tempLabel->setObjectName(QString::fromUtf8("tempLabel"));
        tempLabel->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

        horizontalLayout_4->addWidget(tempLabel);

        label_10 = new QLabel(layoutWidget3);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);

        horizontalLayout_4->setStretch(1, 4);
        horizontalLayout_4->setStretch(2, 1);
        layoutWidget4 = new QWidget(homeForm);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(50, 90, 61, 71));
        verticalLayout_3 = new QVBoxLayout(layoutWidget4);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        manlabel = new QLabel(layoutWidget4);
        manlabel->setObjectName(QString::fromUtf8("manlabel"));

        verticalLayout_3->addWidget(manlabel);

        label_11 = new QLabel(layoutWidget4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_11);

        layoutWidget5 = new QWidget(homeForm);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(320, 310, 51, 91));
        verticalLayout_4 = new QVBoxLayout(layoutWidget5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        smokelabel = new QLabel(layoutWidget5);
        smokelabel->setObjectName(QString::fromUtf8("smokelabel"));

        verticalLayout_4->addWidget(smokelabel);

        label_12 = new QLabel(layoutWidget5);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_12);

        layoutWidget6 = new QWidget(homeForm);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(530, 80, 51, 71));
        verticalLayout_5 = new QVBoxLayout(layoutWidget6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        templabel = new QLabel(layoutWidget6);
        templabel->setObjectName(QString::fromUtf8("templabel"));

        verticalLayout_5->addWidget(templabel);

        label_13 = new QLabel(layoutWidget6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_13);


        retranslateUi(homeForm);

        QMetaObject::connectSlotsByName(homeForm);
    } // setupUi

    void retranslateUi(QWidget *homeForm)
    {
        homeForm->setWindowTitle(QApplication::translate("homeForm", "Form", 0, QApplication::UnicodeUTF8));
        backButton->setText(QString());
        label->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#0055ff;\">100%</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#0055ff;\">50%</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#0055ff;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#ff0000;\">100\342\204\203</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#ff5500;\">50\342\204\203</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; font-weight:600; color:#ff5500;\">0</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#0055ff;\">\346\271\277\345\272\246\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        humLabel->setText(QString());
        label_8->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#0055ff;\">%</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#ff5500;\">\346\270\251\345\272\246\357\274\232</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        tempLabel->setText(QString());
        label_10->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt; color:#ff5500;\">\342\204\203</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        manlabel->setText(QString());
        label_11->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\344\272\272\344\275\223\346\243\200\346\265\213</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\"> \344\274\240\346\204\237\345\231\250</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        smokelabel->setText(QString());
        label_12->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\"> \347\203\237\351\233\276</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\344\274\240\346\204\237\345\231\250</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        templabel->setText(QString());
        label_13->setText(QApplication::translate("homeForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\346\270\251\346\271\277\345\272\246</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">\344\274\240\346\204\237\345\231\250</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class homeForm: public Ui_homeForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEFORM_H

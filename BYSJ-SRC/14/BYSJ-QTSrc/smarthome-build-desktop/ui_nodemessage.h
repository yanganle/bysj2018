/********************************************************************************
** Form generated from reading UI file 'nodemessage.ui'
**
** Created: Mon Oct 15 13:11:44 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEMESSAGE_H
#define UI_NODEMESSAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_nodeMessage
{
public:
    QAction *nodeState;
    QAction *back;
    QAction *declaration;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menubar;
    QMenu *menu_O;
    QMenu *menu_H;

    void setupUi(QMainWindow *nodeMessage)
    {
        if (nodeMessage->objectName().isEmpty())
            nodeMessage->setObjectName(QString::fromUtf8("nodeMessage"));
        nodeMessage->resize(800, 480);
        nodeMessage->setMaximumSize(QSize(800, 480));
        nodeState = new QAction(nodeMessage);
        nodeState->setObjectName(QString::fromUtf8("nodeState"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rcs/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        nodeState->setIcon(icon);
        back = new QAction(nodeMessage);
        back->setObjectName(QString::fromUtf8("back"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rcs/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon1);
        declaration = new QAction(nodeMessage);
        declaration->setObjectName(QString::fromUtf8("declaration"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rcs/declaration.png"), QSize(), QIcon::Normal, QIcon::Off);
        declaration->setIcon(icon2);
        centralwidget = new QWidget(nodeMessage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 13)
            tableWidget->setRowCount(13);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem18);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 10, 731, 381));
        tableWidget->setMaximumSize(QSize(16777215, 381));
        nodeMessage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(nodeMessage);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        nodeMessage->setStatusBar(statusbar);
        toolBar = new QToolBar(nodeMessage);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        nodeMessage->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(nodeMessage);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu_O = new QMenu(menubar);
        menu_O->setObjectName(QString::fromUtf8("menu_O"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        nodeMessage->setMenuBar(menubar);

        toolBar->addAction(nodeState);
        toolBar->addAction(back);
        toolBar->addAction(declaration);
        menubar->addAction(menu_O->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_O->addAction(nodeState);
        menu_O->addSeparator();
        menu_O->addAction(back);
        menu_H->addAction(declaration);

        retranslateUi(nodeMessage);

        QMetaObject::connectSlotsByName(nodeMessage);
    } // setupUi

    void retranslateUi(QMainWindow *nodeMessage)
    {
        nodeMessage->setWindowTitle(QApplication::translate("nodeMessage", "MainWindow", 0, QApplication::UnicodeUTF8));
        nodeState->setText(QApplication::translate("nodeMessage", "\350\212\202\347\202\271\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("nodeMessage", "\350\277\224\345\233\236", 0, QApplication::UnicodeUTF8));
        declaration->setText(QApplication::translate("nodeMessage", "\350\257\246\347\273\206\344\277\241\346\201\257", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("nodeMessage", "\350\212\202\347\202\271\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("nodeMessage", "\350\212\202\347\202\271\347\237\255\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("nodeMessage", "\347\210\266\350\212\202\347\202\271\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("nodeMessage", "\350\212\202\347\202\271\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("nodeMessage", "\350\212\202\347\202\271\346\211\200\347\224\250\351\200\232\351\201\223", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("nodeMessage", "\351\200\232\344\277\241\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("nodeMessage", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("nodeMessage", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("nodeMessage", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("nodeMessage", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("nodeMessage", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("nodeMessage", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("nodeMessage", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem13->setText(QApplication::translate("nodeMessage", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem14->setText(QApplication::translate("nodeMessage", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem15->setText(QApplication::translate("nodeMessage", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem16->setText(QApplication::translate("nodeMessage", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem17->setText(QApplication::translate("nodeMessage", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem18->setText(QApplication::translate("nodeMessage", "13", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("nodeMessage", "toolBar", 0, QApplication::UnicodeUTF8));
        menu_O->setTitle(QApplication::translate("nodeMessage", "\346\211\223\345\274\200(&O)", 0, QApplication::UnicodeUTF8));
        menu_H->setTitle(QApplication::translate("nodeMessage", "\347\211\210\346\234\254\350\257\264\346\230\216(&H)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class nodeMessage: public Ui_nodeMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEMESSAGE_H

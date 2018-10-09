/********************************************************************************
** Form generated from reading UI file 'nodemessage.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODEMESSAGE_H
#define UI_NODEMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

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
            nodeMessage->setObjectName(QStringLiteral("nodeMessage"));
        nodeMessage->resize(800, 480);
        nodeMessage->setMaximumSize(QSize(800, 480));
        nodeState = new QAction(nodeMessage);
        nodeState->setObjectName(QStringLiteral("nodeState"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/rcs/message.png"), QSize(), QIcon::Normal, QIcon::Off);
        nodeState->setIcon(icon);
        back = new QAction(nodeMessage);
        back->setObjectName(QStringLiteral("back"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/rcs/back.png"), QSize(), QIcon::Normal, QIcon::Off);
        back->setIcon(icon1);
        declaration = new QAction(nodeMessage);
        declaration->setObjectName(QStringLiteral("declaration"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rcs/declaration.png"), QSize(), QIcon::Normal, QIcon::Off);
        declaration->setIcon(icon2);
        centralwidget = new QWidget(nodeMessage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        if (tableWidget->rowCount() < 8)
            tableWidget->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setItem(1, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setItem(1, 1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setItem(1, 2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setItem(1, 3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setItem(2, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setItem(2, 1, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setItem(2, 2, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setItem(2, 3, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setItem(3, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setItem(3, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setItem(3, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setItem(3, 3, __qtablewidgetitem28);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(30, 10, 731, 381));
        tableWidget->setMaximumSize(QSize(16777215, 381));
        nodeMessage->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(nodeMessage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        nodeMessage->setStatusBar(statusbar);
        toolBar = new QToolBar(nodeMessage);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        nodeMessage->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(nodeMessage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu_O = new QMenu(menubar);
        menu_O->setObjectName(QStringLiteral("menu_O"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
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
        nodeMessage->setWindowTitle(QApplication::translate("nodeMessage", "MainWindow", 0));
        nodeState->setText(QApplication::translate("nodeMessage", "\350\212\202\347\202\271\347\212\266\346\200\201", 0));
        back->setText(QApplication::translate("nodeMessage", "\350\277\224\345\233\236", 0));
        declaration->setText(QApplication::translate("nodeMessage", "\350\257\246\347\273\206\344\277\241\346\201\257", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("nodeMessage", "\350\215\257\345\223\201\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("nodeMessage", "\350\215\257\345\223\201\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("nodeMessage", "\347\224\237\344\272\247\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("nodeMessage", "\346\234\211\346\225\210\346\234\237\350\207\263", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("nodeMessage", "\346\234\211\346\225\210\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("nodeMessage", "1", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("nodeMessage", "3", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("nodeMessage", "2", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("nodeMessage", "4", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("nodeMessage", "5", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem10->setText(QApplication::translate("nodeMessage", "6", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem11->setText(QApplication::translate("nodeMessage", "7", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem12->setText(QApplication::translate("nodeMessage", "8", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("nodeMessage", "\351\230\277\350\216\253\350\245\277\346\236\227", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(0, 1);
        ___qtablewidgetitem14->setText(QApplication::translate("nodeMessage", "0001", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(0, 2);
        ___qtablewidgetitem15->setText(QApplication::translate("nodeMessage", "2018.10.01", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->item(0, 3);
        ___qtablewidgetitem16->setText(QApplication::translate("nodeMessage", "2018.10.01", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->item(1, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("nodeMessage", "\346\204\237\345\206\222\347\201\265\351\242\227\347\262\222", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->item(1, 1);
        ___qtablewidgetitem18->setText(QApplication::translate("nodeMessage", "0002", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->item(1, 2);
        ___qtablewidgetitem19->setText(QApplication::translate("nodeMessage", "2018.10.02", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->item(1, 3);
        ___qtablewidgetitem20->setText(QApplication::translate("nodeMessage", "2018.10.01", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->item(2, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("nodeMessage", "\351\230\277\345\217\270\345\214\271\346\236\227", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->item(2, 1);
        ___qtablewidgetitem22->setText(QApplication::translate("nodeMessage", "0003", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->item(2, 2);
        ___qtablewidgetitem23->setText(QApplication::translate("nodeMessage", "2018.10.03", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->item(2, 3);
        ___qtablewidgetitem24->setText(QApplication::translate("nodeMessage", "2018.10.01", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->item(3, 0);
        ___qtablewidgetitem25->setText(QApplication::translate("nodeMessage", "\346\260\237\347\275\227\346\262\231\346\230\237", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->item(3, 1);
        ___qtablewidgetitem26->setText(QApplication::translate("nodeMessage", "0004", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->item(3, 2);
        ___qtablewidgetitem27->setText(QApplication::translate("nodeMessage", "2018.10.04", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->item(3, 3);
        ___qtablewidgetitem28->setText(QApplication::translate("nodeMessage", "2018.10.01", 0));
        tableWidget->setSortingEnabled(__sortingEnabled);

        toolBar->setWindowTitle(QApplication::translate("nodeMessage", "toolBar", 0));
        menu_O->setTitle(QApplication::translate("nodeMessage", "\346\211\223\345\274\200(&O)", 0));
        menu_H->setTitle(QApplication::translate("nodeMessage", "\347\211\210\346\234\254\350\257\264\346\230\216(&H)", 0));
    } // retranslateUi

};

namespace Ui {
    class nodeMessage: public Ui_nodeMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODEMESSAGE_H

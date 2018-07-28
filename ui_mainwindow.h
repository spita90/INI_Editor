/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *horizontalWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_new;
    QPushButton *btn_load;
    QPushButton *btn_save;
    QTableWidget *table;
    QWidget *horizontalWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_add;
    QPushButton *btn_remove;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(513, 377);
        MainWindow->setMinimumSize(QSize(400, 300));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalWidget1 = new QWidget(centralWidget);
        horizontalWidget1->setObjectName(QStringLiteral("horizontalWidget1"));
        horizontalLayout = new QHBoxLayout(horizontalWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        btn_new = new QPushButton(horizontalWidget1);
        btn_new->setObjectName(QStringLiteral("btn_new"));

        horizontalLayout->addWidget(btn_new);

        btn_load = new QPushButton(horizontalWidget1);
        btn_load->setObjectName(QStringLiteral("btn_load"));

        horizontalLayout->addWidget(btn_load);

        btn_save = new QPushButton(horizontalWidget1);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setEnabled(false);

        horizontalLayout->addWidget(btn_save);


        verticalLayout_2->addWidget(horizontalWidget1);

        table = new QTableWidget(centralWidget);
        table->setObjectName(QStringLiteral("table"));
        table->setEnabled(false);
        table->setDragDropMode(QAbstractItemView::DragDrop);
        table->setCornerButtonEnabled(false);
        table->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(table);

        horizontalWidget2 = new QWidget(centralWidget);
        horizontalWidget2->setObjectName(QStringLiteral("horizontalWidget2"));
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        btn_add = new QPushButton(horizontalWidget2);
        btn_add->setObjectName(QStringLiteral("btn_add"));
        btn_add->setEnabled(false);

        horizontalLayout_2->addWidget(btn_add);

        btn_remove = new QPushButton(horizontalWidget2);
        btn_remove->setObjectName(QStringLiteral("btn_remove"));
        btn_remove->setEnabled(false);

        horizontalLayout_2->addWidget(btn_remove);


        verticalLayout_2->addWidget(horizontalWidget2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "INI Editor", nullptr));
        btn_new->setText(QApplication::translate("MainWindow", "Nuovo", nullptr));
        btn_load->setText(QApplication::translate("MainWindow", "Carica", nullptr));
        btn_save->setText(QApplication::translate("MainWindow", "Salva", nullptr));
        btn_add->setText(QApplication::translate("MainWindow", "Aggiungi riga", nullptr));
        btn_remove->setText(QApplication::translate("MainWindow", "Rimuovi riga", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

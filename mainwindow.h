#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <iostream>
#include "entry.h"
#include "section.h"
#include "comment.h"
#include "parameter.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:

    void on_btn_new_clicked();

    void on_btn_load_clicked();

    void on_btn_save_clicked();

    void on_btn_add_clicked();

    void on_btn_remove_clicked();

private:
    Ui::MainWindow *ui;

    bool _usingTable;                               //used to know if table is in use or not

    void initTable(Ui::MainWindow* ui, int rows=1);
};

#endif // MAINWINDOW_H

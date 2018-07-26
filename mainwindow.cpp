#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QtCore/QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invalidrowexception.h"
#include "ioexception.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);
    _usingTable = false;

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_new_clicked() {
    if (!_usingTable) {

        initTable(ui);                          //inizializzo la tabella vuota (non fornisco il num. di righe:default:1)

    } else {

        QMessageBox msgBox;
        msgBox.setText("Tabella già in uso");
        msgBox.setInformativeText(
                "La tabella è già in uso. Se crei un nuovo file prima di salvare il corrente perderai i progressi. Vuoi creare comunque un nuovo file senza salvare il corrente?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        int answer = msgBox.exec();
        if (answer == QMessageBox::Yes) {
            _usingTable = false;
            on_btn_new_clicked();
        }
    }
}

void MainWindow::on_btn_load_clicked() {
    if (!_usingTable) {

        QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Apri file INI"), "",
                                                        tr("File INI (*.ini);;Tutti i files (*)"));

        if (fileName.isEmpty())
            return;
        else {

            QFile file(fileName);
            try {
                if (!file.open(QIODevice::ReadOnly)) {
                    QString err("Impossibile aprire il file");
                    throw IOException(err);
                }
            }
            catch (IOException &e) {
                QMessageBox::information(this, e.getInfo(),
                                         file.errorString());
            }

            QList<Entry *> list;                            //lista Template di puntatori a Entry (classe astratta)

            while (!file.atEnd()) {
                try {
                    QString row = file.readLine();              //leggo ogni riga e decido il tipo di Entry da creare
                    //Section, Comment, e Parameter sono derivate di Entry
                    if (row == "\n") {
                        // ignora i ritorni a capo
                    } else {

                        if (row[0] == "[") {
                            if (row.contains("]"))                  //controllo correttezza notazione

                                list.append(new Section(row));

                            else {
                                QString err("Riscontrata sezione con notazione errata");
                                throw InvalidRowException(err);
                            }
                        } else if (row[0] == ";")

                            list.append(new Comment(row));

                        else {
                            QString param = row.section("=", 0,
                                                        0);  //per i parametri tutto ciò a sx del primo "=" va nel Campo
                            QString value = row.section("=",
                                                        1);            //tutto il resto (anche ulteriori "=") va nel Valore

                            if (value.size() > 0)                                   //controllo correttezza notazione
                                list.append(new Parameter(param, value));
                            else {
                                QString err("Riscontrata riga con notazione errata");
                                throw InvalidRowException(err);
                            }

                        }
                    }
                }

                catch (InvalidRowException &e) {
                    std::cout << e.getInfo().toStdString();
                    QMessageBox::information(this, tr("Righe con errori "),
                                             "Riscontrate righe con errori: sono state saltate");
                }
            }

            initTable(ui, list.size());

            for (int i = 0; i < list.size(); i++) {
                list[i]->show(ui->table, i);
            }
        }

    } else {

        QMessageBox msgBox;
        msgBox.setText("Tabella già in uso");
        msgBox.setInformativeText(
                "La tabella è già in uso. Se carichi un nuovo file prima di salvare il corrente perderai i progressi. Vuoi caricare comunque un altro file senza salvare il corrente?");
        msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Yes);
        int answer = msgBox.exec();
        if (answer == QMessageBox::Yes) {
            _usingTable = false;
            on_btn_load_clicked();
        }
    }

}

void MainWindow::on_btn_save_clicked() {

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Salva file INI"), "",
                                                    tr("File INI (*.ini);;Tutti i files (*)"));

    if (fileName.isEmpty())
        return;
    else {

        QFile file(fileName);

        try {
            if (!file.open(QIODevice::WriteOnly)) {
                QString err("Impossibile salvare il file");
                throw IOException(err);
            }
        }
        catch (IOException &e) {
            QMessageBox::information(this, e.getInfo(),
                                     file.errorString());
        }
        QTextStream out(&file);

        for (int i = 0; i < ui->table->rowCount(); i++) {

            QString item = ui->table->item(i, 0)->text();

            if (item[0] == "[" || item[0] == ";") {
                out << item;
            } else {
                out << item + "=" + ui->table->item(i, 1)->text();
            }
        }
    }
}

void MainWindow::on_btn_add_clicked() {
    bool ok = false;

    int row = QInputDialog::getInt(this, "Posizione", "In che posizione aggiungere la nuova riga?",
                                   ui->table->rowCount() + 1, 1, ui->table->rowCount() + 1, -1, &ok);
    if (ok) {
        QString rowType = QInputDialog::getItem(this, "Tipo", "Che tipo di riga deve essere?",
                                                {"Parametro", "Sezione", "Commento"}, 0, false, &ok);

        if (ok) {
            ui->table->insertRow(row - 1);

            if (rowType == "Parametro") {
                QString param = "...campo...";
                QString value = "...valore...";
                Parameter item(param, value);
                item.show(ui->table, row - 1);
            } else if (rowType == "Sezione") {
                QString value = "[...sezione...]";
                Section item(value);
                item.show(ui->table, row - 1);
            } else {
                QString value = ";...commento...";
                Comment item(value);
                item.show(ui->table, row - 1);
            }
        }
    }
}

void MainWindow::on_btn_remove_clicked() {
    int rowCount = ui->table->rowCount();

    if (rowCount > 0) {

        bool ok = false;

        int row = QInputDialog::getInt(this, "Posizione", "Quale riga vuoi rimuovere?", rowCount, 1, rowCount, -1, &ok);

        if (ok) {
            ui->table->removeRow(row - 1);
        }
    } else {

        QMessageBox::information(this, tr("Tabella vuota"), "La tabella è già vuota!");
    }
}


void MainWindow::initTable(Ui::MainWindow *ui, int rows) {
    _usingTable = true;
    ui->btn_save->setEnabled(true);
    ui->btn_add->setEnabled(true);
    ui->btn_remove->setEnabled(true);
    ui->table->setEnabled(true);
    ui->table->setRowCount(rows);
    ui->table->setColumnCount(2);
    ui->table->setHorizontalHeaderLabels(QStringList{"Campo", "Valore"});
    ui->table->setSpan(0, 0, 1, 1);
    if (rows == 1) {
        ui->table->setItem(0, 0, new QTableWidgetItem);
        ui->table->setItem(0, 1, new QTableWidgetItem);
    }
}

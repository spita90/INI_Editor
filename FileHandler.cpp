#include <QtWidgets/QMessageBox>
#include <iostream>
#include <QtCore/QTextStream>
#include "FileHandler.h"
#include "ioexception.h"
#include "section.h"
#include "invalidrowexception.h"
#include "comment.h"
#include "parameter.h"

QList<Entry *> FileHandler::loadFileToList(QFile &file) {
    try {
        if (!file.open(QIODevice::ReadOnly)) {
            QString err("Impossibile aprire il file");
            throw IOException(err);
        }
    }
    catch (IOException &e) {
        QMessageBox::information(nullptr, e.getInfo(),
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
                    QString param = row.section("=", 0, 0); //per i parametri tutto ciò a sx del primo "=" va nel Campo
                    QString value = row.section("=", 1);           //tutto il resto (anche ulteriori "=") va nel Valore

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
            QMessageBox::information(nullptr, "Righe con errori",
                                     "Riscontrate righe con errori: sono state saltate");
        }
    }

    file.close();

    return list;
}

void FileHandler::saveTableToFile(QTableWidget *table, QFile &file) {

    try {

        if (!file.open(QIODevice::WriteOnly)) {

            QString err("Impossibile salvare il file");
            throw IOException(err);
        }
    }

    catch (IOException &e) {
        QMessageBox::information(nullptr, e.getInfo(),
                                 file.errorString());
    }

    QTextStream out(&file);

    for (int i = 0; i < table->rowCount(); i++) {

        QString item = table->item(i, 0)->text();

        if (item[0] == "[" || item[0] == ";") {
            out << item;
        } else {
            out << item + "=" + table->item(i, 1)->text();
        }
    }

    file.close();

    QMessageBox::information(nullptr, "File salvato",
                             "File salvato con successo");
}

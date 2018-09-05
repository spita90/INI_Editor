#include <QtWidgets/QMessageBox>
#include <iostream>
#include <QtCore/QTextStream>
#include "FileHandler.h"
#include "ioexception.h"
#include "section.h"
#include "invalidrowexception.h"
#include "comment.h"
#include "parameter.h"

void FileHandler::loadFileToList(QFile &file, QList <Entry*>& list) {
        if (!file.open(QIODevice::ReadOnly)) {
            QString err("Impossibile aprire il file\n");
            throw IOException(err);
        }
    bool invalidRowErrors=false;                        //trigger for invalid rows exception

    while (!file.atEnd()) {
            QString row = file.readLine();              //read every line and decide the type of class to be instaantiated
            //Section, Comment, and Parameter classes inherit from Entry abstract class
            if (row == "\n") {
                // ignores the "new line"s
            } else {

                if (row[0] == "[") {
                    if (row.contains("]"))                  //check notation correctness

                        list.append(new Section(row));

                    else {
                        invalidRowErrors = true;
                    }

                } else if (row[0] == ";")

                    list.append(new Comment(row));

                else {
                    QString param = row.section("=", 0, 0); //as for parameters, everything at the left of the first "=" goes into Campo
                    QString value = row.section("=", 1);           //everything else (even other "=") goes into Valore

                    if (value.size() > 0)                                   //check notation correctness
                        list.append(new Parameter(param, value));

                    else {
                        invalidRowErrors = true;
                    }
                }
            }
        }

    file.close();

    if (invalidRowErrors){
        QString err("Riscontrate righe con notazione errata\nSono state saltate\n");
        throw InvalidRowException(err);
    }
}

void FileHandler::saveTableToFile(QTableWidget *table, QFile &file) {


        if (!file.open(QIODevice::WriteOnly)) {

            QString err("Impossibile salvare il file\n");
            throw IOException(err);
        }



    QTextStream out(&file);

    for (int i = 0; i < table->rowCount(); i++) {               //read every line of the table

        QString item = table->item(i, 0)->text();

        if (item[0] == "[" || item[0] == ";") {                 //if the line is a Section or a Comment
            out << item;                                        //I write only the single column
        } else {                                                //if the line is a Parameter
            out << item + "=" + table->item(i, 1)->text();      //I write both columns
        }
    }

    file.close();

    QMessageBox::information(nullptr, "File salvato",
                             "File salvato con successo");
}

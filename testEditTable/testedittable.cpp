#include "testedittable.h"
#include "../FileHandler.h"
#include "../ioexception.h"
#include "../invalidrowexception.h"


void testEditTable::editTableTest(){
    QString filename = "TEST_FILE_edit.ini";    //this file has an invalid line for exception test purposes
    QFile file(filename);

    QVERIFY(file.exists());                     //test if file exists


    QTableWidget table;                         //create new table
    QList<Entry *> list;

    auxLoad(file, &table, list);

    QVERIFY(table.item(2,1)->text()=="valore1\n");          //I check if the third line has "valore1" as its value

    table.setItem(2,1,new QTableWidgetItem("valore2"));     //I replace "valore1" with "valore2" in the table

    FileHandler::saveTableToFile(&table, file);

    file.open(QIODevice::WriteOnly | QIODevice::Append);    //I manually add again an invalid line
    file.write("\nRIGA_NON_VALIDA\n");                      //because saveTableToFile doesn't save invalid lines
    file.close();                                           //and finally save the file

    auxLoad(file, &table, list);                            //now I load the saved file again in the table

    QVERIFY(table.item(2,1)->text()=="valore2\n");          //and check if instead of "valore1" now it has "valore2"




    table.setItem(2,1,new QTableWidgetItem("valore1"));     //I reset the table to its original state
    FileHandler::saveTableToFile(&table, file);             //and save the file for future tests.
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    file.write("\nRIGA_NON_VALIDA\n");
    file.close();

};


void testEditTable::auxLoad(QFile& file, QTableWidget* table, QList <Entry*>& list){

    list = {};

    QVERIFY_EXCEPTION_THROWN(FileHandler::loadFileToList(file, list),InvalidRowException);  //test if it actually throws an exception because of the invalid line


    table->setRowCount(list.size());
    table->setColumnCount(2);
    table->setSpan(0, 0, 1, 1);


    for (int i = 0; i < list.size(); i++) {
        list[i]->show(table,i);
    }

};


QTEST_MAIN(testEditTable)

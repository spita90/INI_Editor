#include "testsavefile.h"
#include "../FileHandler.h"


void testSaveFile::saveFileTest(){
    QString filename = "TEST_FILE_output.ini";
    QFile file_write(filename);

    Q_ASSERT(file_write.exists());              //test if file exists


    QTableWidget table;                         //create new table
    table.setRowCount(1);
    table.setColumnCount(2);
    QTableWidgetItem item;                      //this item contains the text [test] - which is 6 characters
    item.setText("[test]");
    table.setItem(0,0,&item);

    FileHandler::saveTableToFile(&table, file_write);   //now I save the file


    QFile file_read(filename);
    Q_ASSERT(file_read.size()==6);              //and verify that the file size is actually 6 bytes


    file_write.open(QIODevice::WriteOnly);      //reset the file for future tests.
    file_write.write("");                       //if we comment these 3 lines the file will not be emptied
    file_write.close();                         //and we could see [test] in it
};



QTEST_MAIN(testSaveFile)

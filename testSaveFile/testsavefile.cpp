#include "testsavefile.h"
#include "../FileHandler.h"


void testSaveFile::saveFileTest(){
    QString filename = "TEST_FILE_output.ini";
    QFile file_write(filename);

    Q_ASSERT(file_write.exists());              //verifico che il file su cui fare il test esista


    QTableWidget table;                         //creo una nuova tabella
    table.setRowCount(1);
    table.setColumnCount(2);
    QTableWidgetItem item;                      //con dentro un item con scritto [test] - sono 6 caratteri
    item.setText("[test]");
    table.setItem(0,0,&item);

    FileHandler::saveFile(file_write,&table);   //lo salvo


    QFile file_read(filename);
    Q_ASSERT(file_read.size()==6);              //verifico che la dim. del file sia 6 byte
};



QTEST_MAIN(testSaveFile)

#include "testloadfile.h"
#include "../FileHandler.h"


void testLoadFile::loadFileTest(){
    QString filename = "TEST_FILE_input.ini";     //è un file con 3 righe valide, una riga non valida, e un accapo
    QFile file(filename);

    Q_ASSERT(file.exists());                //testa se il file di test esiste

    auto list = FileHandler::loadFileToList(file);

    Q_ASSERT(list.size()==3);               //testa se ha letto 3 righe, e saltati quella non valida e l'accapo

};



QTEST_MAIN(testLoadFile);

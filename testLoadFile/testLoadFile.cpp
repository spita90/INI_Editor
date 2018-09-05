#include "testloadfile.h"
#include "../FileHandler.h"


void testLoadFile::loadFileTest(){
    QString filename = "TEST_FILE_input.ini";           //which is a file with 3 valid lines, one invalid line, and a "new line" line
    QFile file(filename);

    QVERIFY(file.exists());                            //test if file exists

    QList<Entry *> list;

    try{
    FileHandler::loadFileToList(file, list);            //using static function: FileHandler class is never istantiated
    }
    catch(...){}

    QVERIFY(list.size()==3);                           //test if it actually read 3 lines, and skipped the invalid and the "new line" ones

};



QTEST_MAIN(testLoadFile)

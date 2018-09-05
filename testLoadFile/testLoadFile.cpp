#include "testloadfile.h"
#include "../FileHandler.h"
#include "../invalidrowexception.h"


void testLoadFile::loadFileTest(){
    QString filename = "TEST_FILE_input.ini";           //which is a file with 3 valid lines, one invalid line, and a "new line" line
    QFile file(filename);

    QVERIFY(file.exists());                            //test if file exists

    QList<Entry *> list;

    QVERIFY_EXCEPTION_THROWN(FileHandler::loadFileToList(file, list),InvalidRowException);  //test if it actually throws an exception because of the invalid line

    QVERIFY(list.size()==3);                           //test if it actually read 3 valid lines, and skipped the "new line" line

};



QTEST_MAIN(testLoadFile)

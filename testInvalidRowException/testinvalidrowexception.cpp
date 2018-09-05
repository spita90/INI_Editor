

#include "testinvalidrowexception.h"
#include "../FileHandler.h"
#include "../invalidrowexception.h"


void testInvalidRowException::InvalidRowExceptionTest(){
    QString filename = "TEST_FILE_exception.ini";   //which is a file with 3 valid lines, one invalid line, and a "new line" line
    QFile file(filename);                           //so it should generate an exception because of the invalid line

    QVERIFY(file.exists());              //test if file exists

    QList<Entry *> list;

    QVERIFY_EXCEPTION_THROWN(FileHandler::loadFileToList(file, list),InvalidRowException);

};



QTEST_MAIN(testInvalidRowException)

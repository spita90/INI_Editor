

#include "testinvalidrowexception.h"
#include "../FileHandler.h"
#include "../invalidrowexception.h"


void testInvalidRowException::InvalidRowExceptionTest(){
    QString filename = "TEST_FILE_exception.ini";   //which is a file with 3 valid lines, one invalid line, and a "new line" line
    QFile file(filename);                           //so it should generate an exception because of the invalid line

    Q_ASSERT(file.exists());              //test if file exists

    QList<Entry *> list;

    bool invalidRowExceptionLaunched = false;

    try{
    FileHandler::loadFileToList(file, list);            //using static function: FileHandler class is never istantiated
    }

    catch (InvalidRowException &e) {
        invalidRowExceptionLaunched =true;
        std::cout << e.getInfo().toStdString();
    }

    Q_ASSERT(invalidRowExceptionLaunched);              //test if FileHandler actually launched an exception beacuse of the invalid line

};



QTEST_MAIN(testInvalidRowException)

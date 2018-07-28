#ifndef INI_EDITOR_FILEHANDLER_H
#define INI_EDITOR_FILEHANDLER_H


#include <QtCore/QFile>
#include "entry.h"

class FileHandler {

public:
    static QList <Entry*> loadFileToList(QFile& file);

    static void saveTableToFile(QTableWidget* table, QFile& file);
};


#endif //INI_EDITOR_FILEHANDLER_H

#ifndef SECTION_H
#define SECTION_H

#include "entry.h"

class Section : public Entry
{
public:
    explicit Section(QString &text){
        _item = new QTableWidgetItem(text);
    }

    void show(QTableWidget* table, int row)override{
        table->setItem(row,0,_item);
        table->setSpan(row,0,1,2);
    }

};

#endif // SECTION_H

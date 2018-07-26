#ifndef COMMENT_H
#define COMMENT_H

#include "entry.h"

class Comment : public Entry
{
public:
    explicit Comment(QString &text){
        _item = new QTableWidgetItem(text);
    }

    void show(QTableWidget* table, int row)override{
        table->setItem(row,0,_item);
        table->setSpan(row,0,1,2);
    }

};

#endif // COMMENT_H

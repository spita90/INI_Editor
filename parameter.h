#ifndef PARAMETER_H
#define PARAMETER_H

#include "entry.h"

class Parameter : public Entry
{
public:
    explicit Parameter(QString &param, QString &value){
        _item = new QTableWidgetItem(param);
        _value = new QTableWidgetItem(value);
    }

    void show(QTableWidget* table, int row)override{
        table->setItem(row,0,_item);
        table->setItem(row,1,_value);
    }

private:
    QTableWidgetItem* _value;


};

#endif // PARAMETER_H

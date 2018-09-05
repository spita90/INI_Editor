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

    void show(QTableWidget* table, int row)override{        //override of the pure virtual inherited method
        table->setItem(row,0,_item);
        table->setItem(row,1,_value);
    }

private:
    QTableWidgetItem* _value;           //the parameter goes into the protected inherited _item, and the value goes into the private _value


};

#endif // PARAMETER_H

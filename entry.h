#ifndef ENTRY_H
#define ENTRY_H

#include <QString>
#include <QtWidgets/QTableWidget>

class Entry
{
public:
    Entry() = default;

    virtual void show(QTableWidget* table, int row)=0;

protected:
    QTableWidgetItem* _item{};
};

#endif // ENTRY_H

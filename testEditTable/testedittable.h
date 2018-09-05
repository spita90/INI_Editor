#ifndef TESTEDITTABLE_H
#define TESTEDITTABLE_H


#include <QtTest>
#include <QCoreApplication>
#include <iostream>
#include "../entry.h"

class testEditTable : public QObject
{
    Q_OBJECT

private slots:
    void editTableTest();

private:
    void auxLoad(QFile& file, QTableWidget* table, QList <Entry*>& list);

};


#endif // TESTEDITTABLE_H

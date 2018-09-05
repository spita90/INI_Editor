#ifndef TESTSAVEFILE_H
#define TESTSAVEFILE_H


#include <QtTest>
#include <QCoreApplication>

class testSaveFile : public QObject
{
    Q_OBJECT

private slots:
    void saveFileTest();
};


#endif // TESTSAVEFILE_H

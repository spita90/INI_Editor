#ifndef TESTINVALIDROWEXCEPTION_H
#define TESTINVALIDROWEXCEPTION_H


#include <QtTest>
#include <QCoreApplication>
#include <iostream>


class testInvalidRowException : public QObject
{
    Q_OBJECT

private slots:
    void InvalidRowExceptionTest();
};


#endif // TESTINVALIDROWEXCEPTION_H

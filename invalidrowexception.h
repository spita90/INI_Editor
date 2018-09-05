#ifndef INVALIDROWEXCEPTION_H
#define INVALIDROWEXCEPTION_H

#include <QString>
#include <stdexcept>

class InvalidRowException: public std::exception{
public:
    explicit InvalidRowException(QString& info):_info(info){}

    QString getInfo(){
        return _info;
    }

private:
    QString _info{};
};



#endif // INVALIDROWEXCEPTION_H

#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include <QString>
#include <stdexcept>

class IOException: public std::exception{
public:
    explicit IOException(QString& info):_info(info){}

    QString getInfo(){
        return _info;
    }

private:
    QString _info{};
};


#endif // IOEXCEPTION_H

#ifndef DATAREADERINTERFACE_HH
#define DATAREADERINTERFACE_HH

#include <QJsonDocument>
namespace Program {
namespace Interface {

class DataReaderInterface
{
    public:
        DataReaderInterface() = default;
        virtual ~DataReaderInterface() = default;

        virtual bool getData(QJsonObject &data, QString &msg) = 0;
};

}

}


#endif // DATAREADERINTERFACE_HH

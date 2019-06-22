#ifndef DATAREADER_HH
#define DATAREADER_HH

#include "datareaderinterface.hh"
#include <QJsonObject>
//#include <QJsonDocument>

namespace Program {

class DataReader: public Interface::DataReaderInterface
{
    public:
        DataReader();
        bool getData(QJsonObject &data, QString &msg);

    private:
        bool readData(QJsonObject &data, QString &msg);

        // Mod -> enemies[],

};
}   // Program
#endif // DATAREADER_HH

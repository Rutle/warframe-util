#ifndef DATAREADER_HH
#define DATAREADER_HH

#include "datareaderinterface.hh"
#include <QJsonObject>

namespace Program {

class DataReader: public Interface::DataReaderInterface
{
    public:
        DataReader();
        //~DataReader();
        bool getData(QJsonDocument &data, QString &msg);

    private:
        bool readData(QJsonDocument &data, QString &msg);

        // Mod -> enemies[],

};
}   // Program
#endif // DATAREADER_HH

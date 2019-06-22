#include "datareader.hh"
#include <QFile>
#include <QByteArray>
//#include <QJsonObject>
#include <QJsonArray>

#include <QDebug>

namespace Program {

DataReader::DataReader()
{

}

bool DataReader::getData(QJsonObject &data, QString &msg)
{
    if(!readData(data, msg)) {

        qDebug() << msg;
        return false;
    }
    //qDebug() << data.isNull();
    return true;
}

bool DataReader::readData(QJsonObject &data, QString &msg)
{
    QFile file("./data/all.json");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open data file.");
        msg = "Couldn't open data file.";
        return false;
    }
    QByteArray saveData{file.readAll()};
    file.close();

    QJsonParseError jsonError;

    QJsonDocument doc = QJsonDocument::fromJson(saveData, &jsonError);
    if( jsonError.error != QJsonParseError::NoError ) {
         qDebug() << "Error: " << jsonError.errorString();
         msg = jsonError.errorString();
         return false;
    } else if( doc.isNull() ) {
         qDebug() << "Null JsonDocument";
         msg = "Document is null.";
         return false;
    }
    msg = "Reading data was successful.";
    data = doc.object();
    return true;
}

}   // Program

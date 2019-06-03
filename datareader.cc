#include "datareader.hh"
#include <QFile>
#include <QDebug>

namespace Program {

DataReader::DataReader()
{

}

bool DataReader::getData(QJsonDocument &data, QString &msg)
{
    if(!readData(data, msg)) {
        qDebug() << msg;
        return false;
    }
    return true;
}

bool DataReader::readData(QJsonDocument &data, QString &msg)
{
    QFile file(QStringLiteral("./data/all.json"));

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open data file.");
        msg = "Couldn't open data file.";
        return false;
    }
    QByteArray saveData{file.readAll()};

    QJsonDocument doc{QJsonDocument::fromJson(saveData)};
    if(doc.isNull()) {
        msg = "Invalid Json document.";
        return false;
    }
    msg = "Reading data was successful.";
    data = doc;
    return true;
}

}   // Program

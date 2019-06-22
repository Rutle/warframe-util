#include "mainwindow.hh"
#include <QApplication>
//#include <QFile>
//#include <QDebug>
//#include <QJsonDocument>
//#include <QJsonArray>
//#include <QJsonObject>
#include "program.hh"
#include "datareader.hh"
#include "programmodel.hh"

#include <QStyleFactory>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette palette;
    palette.setColor(QPalette::Window,QColor(53,53,53));
    palette.setColor(QPalette::WindowText,Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::WindowText,QColor(127,127,127));
    palette.setColor(QPalette::Base,QColor(42,42,42));
    palette.setColor(QPalette::AlternateBase,QColor(66,66,66));
    palette.setColor(QPalette::ToolTipBase,Qt::white);
    palette.setColor(QPalette::ToolTipText,QColor(53,53,53));
    palette.setColor(QPalette::Text,Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::Text,QColor(127,127,127));
    palette.setColor(QPalette::Dark,QColor(35,35,35));
    palette.setColor(QPalette::Shadow,QColor(20,20,20));
    palette.setColor(QPalette::Button,QColor(53,53,53));
    palette.setColor(QPalette::ButtonText,Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::ButtonText,QColor(127,127,127));
    palette.setColor(QPalette::BrightText,Qt::red);
    palette.setColor(QPalette::Link,QColor(42,130,218));
    palette.setColor(QPalette::Highlight,QColor(42,130,218));
    palette.setColor(QPalette::Disabled,QPalette::Highlight,QColor(80,80,80));
    palette.setColor(QPalette::HighlightedText,Qt::white);
    palette.setColor(QPalette::Disabled,QPalette::HighlightedText,QColor(127,127,127));
    qApp->setPalette(palette);
    /*
    QFile file(QStringLiteral("./data/all.json"));
    qDebug() << file.exists();
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open data file.");
        //msg = "Couldn't open data file.";
        return false;
    }

    //QString val = QString::fromUtf8(file.readAll());
    //qDebug() << "val empty: " << val.isEmpty();
    QByteArray saveData{file.readAll()};
    file.close();
    qDebug() << "savedata empty: " << saveData.isEmpty();
    //QJsonParseError *tmp = nullptr;
    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(saveData, &jsonError);
    qDebug() << "doc on object: " << doc.isObject();

    //qDebug() << doc.object().isEmpty();
    qDebug() << "modSources size: " << doc.object().value("modSources");
    if( jsonError.error != QJsonParseError::NoError )
         qDebug() << "Error: " << jsonError.errorString();
    else if( doc.isNull() )
         qDebug() << "Null JsonDocument";
    //QJsonDocument doc{QJsonDocument::fromJson(file.readAll())};
    //qDebug() << tmp->error;
    qDebug() << "Doc empty: " << doc.isEmpty();

    if(doc.isNull()) {
        //msg = "Invalid Json document.";
        return false;
    }
    //msg = "Reading data was successful.";
    //qDebug() << "readData: " << msg;
    //data = doc;
    qDebug() << "data null: " << doc.isNull();
    qDebug() << "modSources size: " << doc.object().value("modSources").toArray().size();
    return true;
    */
    Program::DataReader *reader{new Program::DataReader()};
    Program::ProgramModel *model{new Program::ProgramModel()};
    Program::Program m{Program::Program()};
    m.setModel(model);
    m.setReader(reader);
    m.setUp();



    m.show();

    return a.exec();

}

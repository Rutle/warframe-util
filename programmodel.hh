#ifndef PROGRAMMODEL_HH
#define PROGRAMMODEL_HH

#include "programmodelinterface.hh"
#include "mod.hh"
//#include "drop.hh"
#include "relic.hh"
#include "prime.hh"
#include <QJsonObject>
#include <QVector>
#include <QMap>

namespace Program {
enum DataCategories { All, BlueprintSources, CetusBountyRewards,
                      EnemyBlueprintTables, EnemyModTables,
                      KeyRewards, MiscItems, MissionRewards,
                      ModSources, Relics, SortieRewards, TransientRewards };

class ProgramModel: public Interface::ProgramModelInterface
{
    public:
        ProgramModel();
        ~ProgramModel();
        void setReader(Interface::DataReaderInterface *reader);
        bool readData(QString &msg);
        const QVector<std::shared_ptr<Data::Drop>> &getModData();
        const QVector<std::shared_ptr<Data::Drop>> &getPrimeData();
        const QStringList &getSelectedCats() const;
    private:
        void parseData();
        bool checkKeys();
        bool parseSelectedKeys(const QStringList &skeys);
        void addMods(const QJsonArray &arr);
        void addRelics(const QJsonArray &arr);
        void setSignals();
        Interface::DataReaderInterface *reader_;
        // Settings *settings_;
        QJsonObject fullData_;
        QStringList dataKeys_;
        QStringList selectedCats_;

        QVector<std::shared_ptr<Data::Drop>> mods_;
        QVector<std::shared_ptr<Data::Relic>> relics_;
        QVector<std::shared_ptr<Data::Drop>> primes_;
        //QVector<std::shared_ptr<Data::DataEntity>> data_;
        QMap<QString, std::shared_ptr<Data::Prime>> primeLookUp_;



};
} // Program
#endif // PROGRAMMODEL_HH

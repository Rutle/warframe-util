#ifndef PROGRAMMODEL_HH
#define PROGRAMMODEL_HH

#include "programmodelinterface.hh"
#include "mod.hh"
#include "relic.hh"
#include "prime.hh"
#include <QJsonObject>
#include <QVector>

namespace Program {
enum DataCategories { All, BlueprintLocations, CetusBountyRewards,
                      EnemyBlueprintTables, EnemyModTables,
                      KeyRewards, MiscItems, MissionRewards,
                      ModLocations, Relics, SortieRewards, TransientRewards };
class ProgramModel: public Interface::ProgramModelInterface
{
    public:
        ProgramModel();
        ~ProgramModel();
        void setReader(Interface::DataReaderInterface *reader);
        bool readData(QString &msg);
        const QVector<Data::Mod> &getMods();
        bool searchMods(const QString &searchParameter,
                        QVector<Data::Mod> &cont) const;
        std::shared_ptr<QVector<Data::Mod>> getModData() const;
    private:
        void parseData(const DataCategories &cat = All);
        void addMods(const QJsonArray &arr);
        void addRelics(const QJsonArray &arr);
        Interface::DataReaderInterface *reader_;
        QJsonDocument fullData_;
        QVector<Data::Mod> mods_;
        QVector<Data::Relic> relics_;
        QVector<Data::Prime> primes_;

};
} // Program
#endif // PROGRAMMODEL_HH

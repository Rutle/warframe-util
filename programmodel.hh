#ifndef PROGRAMMODEL_HH
#define PROGRAMMODEL_HH

#include "programmodelinterface.hh"
#include "mod.hh"
#include "relic.hh"
#include "prime.hh"
#include <QJsonObject>
#include <QVector>
#include <QMap>

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
        std::shared_ptr<QVector<Data::Mod>> getModData() const;
    private:
        void parseData();
        bool checkKeys();
        bool parseSelectedKeys(const QStringList &skeys);
        void addMods(const QJsonArray &arr);
        void addRelics(const QJsonArray &arr);

        Interface::DataReaderInterface *reader_;
        QJsonDocument fullData_;
        QStringList dataKeys_;
        QList<QString> selectedDataKeys_;
        QVector<Data::Mod> mods_;
        QVector<Data::Relic> relics_;
        QVector<Data::Prime> primes_;
        QMap<QString, std::shared_ptr<Data::Prime> > primeLookUp_;

};
} // Program
#endif // PROGRAMMODEL_HH

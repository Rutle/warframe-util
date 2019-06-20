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
        std::shared_ptr<QVector<Data::Mod>> getModData() const;
        std::shared_ptr<QVector<std::shared_ptr<Data::Prime>>> getPrimeData() const;
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
        QJsonDocument fullData_;
        QStringList dataKeys_;
        QStringList selectedCats_;
        QVector<Data::Mod> mods_;
        QVector<std::shared_ptr<Data::Relic>> relics_;
        QVector<std::shared_ptr<Data::Prime> > primes_;
        QVector<std::shared_ptr<Data::DataEntity>> data_;
        QMap<QString, std::shared_ptr<Data::Prime>> primeLookUp_;



};
} // Program
#endif // PROGRAMMODEL_HH

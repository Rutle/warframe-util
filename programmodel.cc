#include "programmodel.hh"
#include "mod.hh"
#include "relic.hh"
#include "enemy.hh"
#include "relicsource.hh"
//#include "dataentity.hh"
#include <QDebug>
#include <QMap>
#include <QJsonArray>
namespace Program {

const QMap<DataCategories, QString> CATEGORIES = {
    {BlueprintSources,"blueprintSources"}, {CetusBountyRewards,"cetusBountyRewards"},
    {EnemyBlueprintTables,"enemyBlueprintTables"}, {EnemyModTables,"enemyModTables"},
    {KeyRewards,"keyRewards"}, {MiscItems,"miscItems"},
    {MissionRewards,"missionRewards"}, {ModSources,"modLocations"},
    {Relics,"relics"}, {SortieRewards,"sortieRewards"},
    {TransientRewards,"transientRewards"},
};
const QMap<QString, QString> CATTOKEY = {
    {"Mods", "modLocations"}, {"Primes", "relics"}
};
ProgramModel::ProgramModel():
    reader_{nullptr}
{
    selectedCats_ << "Mods";
    selectedCats_ << "Primes";
}

ProgramModel::~ProgramModel()
{
    delete reader_;
    //delete fullData_;
}

void ProgramModel::setReader(Interface::DataReaderInterface *reader)
{
    reader_ = reader;

}

bool ProgramModel::readData(QString &msg)
{
    if(!reader_->getData(fullData_, msg)) {
        qDebug() << "ProgramModel message after: " << msg;
        return false;
    }
    if(!checkKeys()) {
        msg = "Key check failed.";
        return false;
    }
    parseData();
    return true;
}

const QVector<std::shared_ptr<Data::Drop>> &ProgramModel::getModData()
{
    return mods_;
}

const QVector<std::shared_ptr<Data::Drop>> &ProgramModel::getPrimeData()
{
    return primes_;
}

const QStringList &ProgramModel::getSelectedCats() const
{
    return selectedCats_;
}

void ProgramModel::parseData()
{
    if(selectedCats_.contains("Mods")) {

        addMods(fullData_.value(CATTOKEY.value("Mods")).toArray());
    }

    if(selectedCats_.contains("Primes")) {
        addRelics(fullData_.value(CATTOKEY.value("Primes")).toArray());
    }



}

bool ProgramModel::checkKeys()
{
    QStringList keys{fullData_.keys()};
    qDebug() << "keys: " << keys;
    if(!keys.isEmpty()) {
        dataKeys_ = keys;
        return true;
    }
    return false;
}

void ProgramModel::addMods(const QJsonArray &arr)
{
    for (auto item : arr) {
        QString name{item.toObject().value("modName").toString()};
        QString id{item.toObject().value("_id").toString()};
        QJsonArray enemies = item.toObject().value("enemies").toArray();
        auto tmp{std::make_shared<Data::Mod>(
                        id, name, Data::DROPTYPE::MODDROP)};

        for (auto enemy : enemies) {
            QString enemyId{enemy.toObject().value("_id").toString()};
            QString enemyName{enemy.toObject().value("enemyName").toString()};
            QString dropChance{enemy.toObject().value("enemyModDropChance").toString()};
            QString chance{QString::number(enemy.toObject().value("chance").toDouble())};
            QString rarity{enemy.toObject().value("rarity").toString()};
            auto tmpE{std::make_shared<Data::Enemy>(
                            enemyId, enemyName, Data::SOURCETYPE::ENEMYSOURCE,
                            dropChance, rarity, chance)};

            tmp->addSource(tmpE, Data::SOURCETYPE::ENEMYSOURCE);
        }
        mods_.append(tmp);
    }
}

void ProgramModel::addRelics(const QJsonArray &arr)
{
    for (auto item : arr) {
        QString state{item.toObject().value("state").toString()};
        if (state == "Intact") {
            QString relicName{item.toObject().value("relicName").toString()};
            QString relicId{item.toObject().value("_id").toString()};
            QString relicTier{item.toObject().value("tier").toString()};
            QJsonArray rewards = item.toObject().value("rewards").toArray();

            //auto tmpRelic{std::make_shared<Data::Relic>(relicId, relicName, Data::DROPTYPE::RELICDROP, relicTier)};
            //relics_.append(tmpRelic);
            for (auto prime : rewards) {
                QString primeId{prime.toObject().value("_id").toString()};
                QString primeName{prime.toObject().value("itemName").toString()};
                QString chance{prime.toObject().value("chance").toString()};
                QString rarity{prime.toObject().value("rarity").toString()};

                auto tmpPrime{std::make_shared<Data::Prime>(
                                primeId, primeName,
                                Data::DROPTYPE::PRIMEDROP)};

                if (!primeLookUp_.contains(primeId)) {
                    tmpPrime->addSource(
                                std::make_shared<Data::RelicSource>(
                                    chance, rarity, relicId, relicName,
                                    relicTier, Data::SOURCETYPE::RELICSOURCE),
                                Data::SOURCETYPE::RELICSOURCE);
                    //tmpPrime->addSource(tmpRelic, chance, rarity);
                    primeLookUp_.insert(primeId, tmpPrime);
                    primes_.append(tmpPrime);

                } else {
                    primeLookUp_[primeId]->addSource(
                                std::make_shared<Data::RelicSource>(
                                    chance, rarity, relicId, relicName,
                                    relicTier, Data::SOURCETYPE::RELICSOURCE),
                                Data::SOURCETYPE::RELICSOURCE);
                    //qDebug() << "Exists already: "
                    //         << primeLookUp_.value(primeId)->getSourceCount(
                    //                Data::SOURCETYPE::RELICSOURCE);
                }
                /*
                int idx{primes_.indexOf(tmpPrime)};
                if(idx == -1) {
                    tmpPrime.addRelic(std::make_shared<Data::Relic>(tmpRelic),
                                      chance, rarity);
                    primes_.append(tmpPrime);
                } else {
                    primes_.value(idx).addRelic(std::make_shared<Data::Relic>(tmpRelic),
                                                chance, rarity);
                    qDebug() << primes_.value(idx).getRelicCount();
                    qDebug() << primeId << " already existed.";
                }*/

            }
        }


    }
    //qDebug() << "eka " << primes_.at(0)->getName() << " " << primes_.at(0)->getRelicCount();
    //qDebug() << "eka " << primeLookUp_.value("6733cc5298452209aa29dd72027c7df1")->getName() << " " << primeLookUp_.value("6733cc5298452209aa29dd72027c7df1")->getRelicCount();
}


} // Program


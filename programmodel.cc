#include "programmodel.hh"
#include "mod.hh"
#include "relic.hh"
#include "dataentity.hh"
#include <QDebug>
#include <QMap>
#include <QJsonArray>
namespace Program {

const QMap<DataCategories, QString> CATEGORIES = {
    {BlueprintSources,"blueprintSources"}, {CetusBountyRewards,"cetusBountyRewards"},
    {EnemyBlueprintTables,"enemyBlueprintTables"}, {EnemyModTables,"enemyModTables"},
    {KeyRewards,"keyRewards"}, {MiscItems,"miscItems"},
    {MissionRewards,"missionRewards"}, {ModSources,"modSources"},
    {Relics,"relics"}, {SortieRewards,"sortieRewards"},
    {TransientRewards,"transientRewards"},
};
const QMap<QString, QString> CATTOKEY = {
    {"Mods", "modSources"}, {"Primes", "relics"}
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
        //qDebug() << "ProgramModel message after: " << msg;
        return false;
    }
    if(fullData_.isNull()) {
        msg = "Data was not loaded.";
        return false;
    }
    if(!checkKeys()) {
        msg = "Key check failed.";
        return false;
    }
    parseData();
    return true;
}

std::shared_ptr<QVector<Data::Mod>> ProgramModel::getModData() const
{
    return std::make_shared<QVector<Data::Mod>>(mods_);
}

std::shared_ptr<QVector<std::shared_ptr<Data::Prime>>> ProgramModel::getPrimeData() const
{
    qDebug() << "Primes: ";
    qDebug() << primes_.at(0)->getName();
    qDebug() << primes_.size();
    return std::make_shared<QVector<std::shared_ptr<Data::Prime>>>(primes_);
}

const QStringList &ProgramModel::getSelectedCats() const
{
    return selectedCats_;
}

void ProgramModel::parseData()
{
    //QString category{CATEGORIES.value(cat)};
    //qDebug() << category;
    //qDebug() << fullData_.object().size();
    // Do not use QJsonArray tmp{} <- brackets. Does not work properly.

    //qDebug() << tmpData.size();
    //qDebug() << tmpData.at(0).toObject().value("_id").toString();
    //qDebug() << tmpData.at(0).toObject().value("enemies").toArray().size();
    //QJsonArray tmpData = fullData_.object().value(category).toArray();
    // _id string of the first mod
    //selectedDataKeys_.contains();
    if(selectedCats_.contains("Mods")) {
        addMods(fullData_.object().value(CATTOKEY.value("Mods")).toArray());
    }
    if(selectedCats_.contains("Primes")) {
        addRelics(fullData_.object().value(CATTOKEY.value("Primes")).toArray());
    }
    //Data::Prime *tmp = new Data::Prime;
    //tmp->
    qDebug() << mods_.size();
    qDebug() << primes_.size();
    qDebug() << primes_.at(0)->getName();

}

bool ProgramModel::checkKeys()
{
    QStringList keys{fullData_.object().keys()};
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
        Data::Mod tmp{id, name, Data::ModType};
        for (auto enemy : enemies) {
            QString enemyId{enemy.toObject().value("_id").toString()};
            QString enemyName{enemy.toObject().value("enemyName").toString()};
            double dropChance{enemy.toObject().value("enemyModDropChance").toDouble()};
            double chance{enemy.toObject().value("chance").toDouble()};
            QString rarity{enemy.toObject().value("rarity").toString()};
            Data::Enemy tmpE{enemyId, enemyName, Data::EnemyType};
            tmpE.setStats(dropChance, rarity, chance);
            tmp.addEnemy(std::make_shared<Data::Enemy>(tmpE));
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

            auto tmpRelic{std::make_shared<Data::Relic>(relicId, relicName, Data::RelicType, relicTier)};
            relics_.append(tmpRelic);
            for (auto prime : rewards) {
                QString primeId{prime.toObject().value("_id").toString()};
                QString primeName{prime.toObject().value("itemName").toString()};
                auto tmpPrime{std::make_shared<Data::Prime>(primeId, primeName, Data::PrimeType)};
                int chance{prime.toObject().value("chance").toInt()};
                QString rarity{prime.toObject().value("rarity").toString()};
                // Make a lookup table with map/hash based on Id for faster checking?
                if (!primeLookUp_.contains(primeId)) {
                    tmpPrime->addRelic(tmpRelic, chance, rarity);
                    primeLookUp_.insert(primeId, tmpPrime);
                    primes_.append(tmpPrime);

                } else {
                    primeLookUp_[primeId]->addRelic(tmpRelic, chance, rarity);
                    qDebug() << "Exists already: "  << primeLookUp_.value(primeId)->getRelicCount();
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
    qDebug() << "eka " << primes_.at(0)->getName() << " " << primes_.at(0)->getRelicCount();
    qDebug() << "eka " << primeLookUp_.value("6733cc5298452209aa29dd72027c7df1")->getName() << " " << primeLookUp_.value("6733cc5298452209aa29dd72027c7df1")->getRelicCount();
}


} // Program


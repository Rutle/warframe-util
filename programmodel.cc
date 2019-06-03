#include "programmodel.hh"
#include "mod.hh"
#include "relic.hh"
#include <QDebug>
#include <QMap>
#include <QJsonArray>
namespace Program {

const QMap<DataCategories, QString> CATEGORIES = {
    {BlueprintLocations,"blueprintLocations"}, {CetusBountyRewards,"cetusBountyRewards"},
    {EnemyBlueprintTables,"enemyBlueprintTables"}, {EnemyModTables,"enemyModTables"},
    {KeyRewards,"keyRewards"}, {MiscItems,"miscItems"},
    {MissionRewards,"missionRewards"}, {ModLocations,"modLocations"},
    {Relics,"relics"}, {SortieRewards,"sortieRewards"},
    {TransientRewards,"transientRewards"},
};
const QMap<QString, QString> SHORTHAND = {
    {"modLocations", "Mods"}, {"relics", "Relics"},
};

ProgramModel::ProgramModel():
    reader_{nullptr}
{
    selectedDataKeys_.append("modLocations");
    selectedDataKeys_.append("relics");
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
    //qDebug() << "IsNull?: " << fullData_.isNull();
    //qDebug() << msg;
    //qDebug() << fullData_.object().keys();
    if(fullData_.isNull()) {
        msg = "Data was not loaded.";
        return false;
    }
    if(!checkKeys()) {
        msg = "Key check failed.";
        return false;
    }
    parseData();
    //parseData(ModLocations); // Where each mod drops (enemies only).
    //parseData(Relics); // Prime parts from relics.

    return true;
}

const QVector<Data::Mod> &ProgramModel::getMods()
{
    return mods_;
}

std::shared_ptr<QVector<Data::Mod> > ProgramModel::getModData() const
{
    return std::make_shared<QVector<Data::Mod>>(mods_);
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
    if(selectedDataKeys_.contains(CATEGORIES.value(ModLocations))) {
        qDebug() << "contains " << CATEGORIES.value(ModLocations);
        addMods(fullData_.object().value(
                    CATEGORIES.value(ModLocations)).toArray());
    }
    if(selectedDataKeys_.contains(CATEGORIES.value(Relics))) {
        qDebug() << "contains " << CATEGORIES.value(Relics);
        addRelics(fullData_.object().value(
                    CATEGORIES.value(Relics)).toArray());
    }
    //if(cat == ModLocations) {
    //    addMods(tmpData);
    //}
    //if (cat == Relics) {
    //    //addRelics(tmpData);
    //}
    qDebug() << mods_.size();
    qDebug() << primes_.size();
    //qDebug() << mods_.at(0).enemyCount();


    //qDebug() << tmp.value(CATEGORIES.value(cat)).toArray().at(0).toObject().value("modName").toString();
    //qDebug() <<

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
            int chance{enemy.toObject().value("chance").toInt()};
            QString rarity{enemy.toObject().value("rarity").toString()};
            Data::Enemy tmpE{enemyId, enemyName, Data::EnemyType};
            tmpE.setStats(dropChance, rarity, chance);
            tmp.addEnemy(std::make_shared<Data::Enemy>(tmpE));
        }
        mods_.append(tmp);
    }

    //sortMods(mods_);
    //QVector<Data::Mod> test;
    //if(searchMods("drift", test)) {
    //    qDebug() << test.at(0).getName();
    //}

}

void ProgramModel::addRelics(const QJsonArray &arr)
{
    for (auto item : arr) {
        QString relicName{item.toObject().value("relicName").toString()};
        QString relicId{item.toObject().value("_id").toString()};
        QString relicTier{item.toObject().value("tier").toString()};
        QJsonArray rewards = item.toObject().value("rewards").toArray();
        Data::Relic tmpRelic{relicId, relicName, Data::RelicType, relicTier};
        for (auto prime : rewards) {
            QString primeId{prime.toObject().value("_id").toString()};
            QString primeName{prime.toObject().value("itemName").toString()};
            Data::Prime tmpPrime{primeId, primeName, Data::PrimeType};
            int chance{prime.toObject().value("chance").toInt()};
            QString rarity{prime.toObject().value("rarity").toString()};
            // Make a lookup table with map/hash based on Id for faster checking?

            int idx{primes_.indexOf(tmpPrime)};
            if(idx == -1) {
                tmpPrime.addRelic(std::make_shared<Data::Relic>(tmpRelic),
                                  chance, rarity);
                primes_.append(tmpPrime);
            } else {
                primes_.value(idx).addRelic(std::make_shared<Data::Relic>(tmpRelic),
                                            chance, rarity);
                //qDebug() << primeId << " already existed.";
            }

        }

    }
}


} // Program


#include "programmodel.hh"
#include "mod.hh"
#include "misc.hh"
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
    {TransientRewards,"transientRewards"}, {All,"all"},
};

ProgramModel::ProgramModel():
    reader_{nullptr}
{

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
    qDebug() << "IsNull?: " << fullData_.isNull();
    qDebug() << msg;
    qDebug() << fullData_.object().keys();
    parseData(ModLocations); // Where each mod drops (enemies only).
    parseData(Relics); // Prime parts from relics.

    return true;
}

const QVector<Data::Mod> &ProgramModel::getMods()
{
    return mods_;
}

bool ProgramModel::searchMods(const QString &searchString,
                              QVector<Data::Mod> &data) const
{
    QVector<Data::Mod> tmp;
    qDebug() << searchString;
    for (auto mod : mods_) {
        if(mod.getName().toLower().contains(searchString.toLower())) {
            tmp.append(mod);
            //qDebug() << mod.getName();
        }

    }
    if(tmp.isEmpty()){
        return false;
    }
    data = tmp;
    return true;
}

std::shared_ptr<QVector<Data::Mod> > ProgramModel::getModData() const
{
    return std::make_shared<QVector<Data::Mod>>(mods_);
}



void ProgramModel::parseData(const DataCategories &cat)
{
    QString category{CATEGORIES.value(cat)};
    qDebug() << category;
    //qDebug() << fullData_.object().size();
    // Do not use QJsonArray tmp{} <- brackets. Does not work properly.

    //qDebug() << tmpData.size();
    //qDebug() << tmpData.at(0).toObject().value("_id").toString();
    //qDebug() << tmpData.at(0).toObject().value("enemies").toArray().size();
    QJsonArray tmpData = fullData_.object().value(category).toArray();
    // _id string of the first mod
    if(cat == ModLocations) {
        addMods(tmpData);
    } else if (cat == Relics) {
        addRelics(tmpData);
    }
    qDebug() << mods_.size();
    //qDebug() << mods_.at(0).enemyCount();


    //qDebug() << tmp.value(CATEGORIES.value(cat)).toArray().at(0).toObject().value("modName").toString();
    //qDebug() <<

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
        Data::Relic tmp{relicId, relicName, Data::RelicType, relicTier};
        for (auto prime : rewards) {
            QString primeId{prime.toObject().value("_id").toString()};
            QString primeName{prime.toObject().value("itemName").toString()};
            double dropChance{prime.toObject().value("chance").toDouble()};
            //int chance{enemy.toObject().value("chance").toInt()};
            QString rarity{prime.toObject().value("rarity").toString()};
            //Data::Relic tmpE{enemyId, enemyName, Data::EnemyType};
            //tmpE.setStats(dropChance, rarity, chance);
            //tmp.addEnemy(std::make_shared<Data::Enemy>(tmpE));

        }
        //primes_.append(tmp);
    }
}


} // Program


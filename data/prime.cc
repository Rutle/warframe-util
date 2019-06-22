#include "prime.hh"
#include <QDebug>
namespace Program {
namespace Data {


Prime::Prime(): Drop(QString(), QString(), DROPTYPE::UNDEFINED)
{

}

Prime::Prime(const QString &id, const QString &name, const DROPTYPE &type):
    Drop(id, name, type)
{

}
/*
bool Prime::addSource(std::shared_ptr<Source> loc, SOURCETYPE type)
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE:
            return false;
        case SOURCETYPE::ENEMYSOURCE:
            return false;
        case SOURCETYPE::RELICSOURCE: {
            relics_.append(loc);
            return true;
        }
        default:
            return false;

    }
}

QList<QVariant> Prime::getSources(SOURCETYPE type)
{
    QList<QVariant> tmp;

    //relics_.at(0).getData();
    //for (int idx = 0; idx < relics_.size(); ++idx) {
    //    relics_.at(idx)
    //}
    for (auto relic : relics_) {
        //QStringList tmpSL{relic.relic_->getData().toStringList()};

        //tmpSL << QString::number(relic.chance_);
        //tmpSL << relic.rarity_;
        //tmp.append(QVariant(tmpSL));
    }
    qDebug() << "get Relics: " << relics_.size();
    return tmp;
}
*/
} // Data
} // Program

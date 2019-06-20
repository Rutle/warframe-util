#include "prime.hh"
#include <QDebug>
namespace Program {
namespace Data {


Prime::Prime()
{

}

Program::Data::Prime::Prime(const QString &id, const QString &name,
                            const Program::Data::ENTITY &type) :
    DataEntity (id, name, type)
{

}

void Prime::addRelic(std::shared_ptr<Relic> relic, const double &chance, const QString &rarity)
{
    relics_.append(RelicInfo(relic, chance, rarity));
    //qDebug() << "Prime's relics: " << relics_.size();

}

bool Prime::operator==(const Prime &other) const
{

    if(this->getId()==(other.getId())) {
        //qDebug() << this->getId() << " " << other.getId() << " ---> TRUE";
        return true;
    }
    return false;

}

int Prime::getRelicCount() const
{
    return relics_.size();
}

QList<QVariant> Prime::getRelics() const
{
    QList<QVariant> tmp;
    for (auto relic : relics_) {
        QStringList tmpSL{relic.relic_->getData().toStringList()};

        tmpSL << QString::number(relic.chance_);
        tmpSL << relic.rarity_;
        tmp.append(QVariant(tmpSL));
    }
    qDebug() << "get Relics: " << relics_.size();
    return tmp;
}

} // Data
} // Program

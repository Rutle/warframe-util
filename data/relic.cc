#include "relic.hh"
namespace Program {
namespace Data {
Relic::Relic(): Drop(QString(), QString(), DROPTYPE::UNDEFINED)
{

}
Relic::Relic(const QString &id, const QString &name, const DROPTYPE &type,
             const QString &tier):
    Drop(id, name, type), tier_{tier}
{

}
/*
QList<QVariant> Relic::getSources(SOURCETYPE type)
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE: {
            QList<QVariant> tmp;
            for (auto mission : missions_) {
                tmp.append(mission->getData());
            }
            return tmp;
        }
        case SOURCETYPE::ENEMYSOURCE:
            return QList<QVariant>();
        case SOURCETYPE::RELICSOURCE:
            return QList<QVariant>();
        default:
            return QList<QVariant>();
    }
}

bool Relic::addSource(std::shared_ptr<Source> loc, SOURCETYPE type)
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE:
            missions_.append(loc);
            return true;
        case SOURCETYPE::ENEMYSOURCE:
            return false;
        case SOURCETYPE::RELICSOURCE:
            return true;
        default:
            return false;
    }
}

QStringList Relic::getDetails() const
{

}

int Relic::getSourceCount(SOURCETYPE type) const
{

}

const QString &Relic::getName() const
{
    return name_;
}

const DROPTYPE &Relic::getType() const
{
    return type_;
}

const QString &Relic::getId() const
{
    return id_;
}

QVariant Relic::getData() const
{
    QStringList tmp;
    tmp << name_;
    tmp << tier_;
    //tmp << QString::number(chance_);
    return QVariant(tmp);
}*/
}   // Data
}   // Program

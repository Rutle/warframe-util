#include "misc.hh"
namespace Program {
namespace Data {
Misc::Misc(): Drop(QString(), QString(), DROPTYPE::UNDEFINED)
{

}

Misc::Misc(const QString &id, const QString &name, const DROPTYPE &type):
    Drop(id, name, type)
{

}
/*
QList<QVariant> Misc::getSources(SOURCETYPE type)
{

}

bool Misc::addSource(std::shared_ptr<Source> loc, SOURCETYPE type)
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE: {
            missions_.append(loc);
            return true;
        }
        default:
            return false;
    }
}

QStringList Misc::getDetails() const
{
    QStringList tmp;
    tmp << name_;
    tmp << id_;
    return tmp;
}

int Misc::getSourceCount(SOURCETYPE type) const
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE:
            return missions_.size();
    }
}

const QString &Misc::getName() const
{
    return name_;
}

const DROPTYPE &Misc::getType() const
{
    return type_;
}

const QString &Misc::getId() const
{
    return id_;
}
*/
}}

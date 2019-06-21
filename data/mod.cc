#include "mod.hh"
namespace Program {
namespace Data {

Mod::Mod(): id_{QString()}, name_{QString()},
{

}

Mod::Mod(const QString &id, const QString &name, const DROPTYPE &type):
    id_{id}, name_{name}, type_{type}
{

}

bool Mod::addSource(std::shared_ptr<Source> loc, SOURCETYPE type)
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE:
            missions_.append(loc);
            return true;
        case SOURCETYPE::ENEMYSOURCE:
            enemies_.append(loc);
            return true;
        case SOURCETYPE::RELICSOURCE:
            return false;
        default:
            return false;

    }
}

int Mod::getSourceCount(SOURCETYPE type) const
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE:
            return missions_.size();
        case SOURCETYPE::ENEMYSOURCE:
            return enemies_.size();
        case SOURCETYPE::RELICSOURCE:
            return 0;
        default:
            return 0;
    }
}

QList<QVariant> Mod::getSources(SOURCETYPE type)
{
    switch (type) {
        case SOURCETYPE::MISSIONSOURCE: {
            QList<QVariant> tmp;
            for (auto mission : missions_) {
                tmp.append(mission->getData());
            }
            return tmp;
        }
        case SOURCETYPE::ENEMYSOURCE: {
            QList<QVariant> tmp;
            for (auto enemy : enemies_) {
                tmp.append(enemy->getData());
            }
            return tmp;
        }
        case SOURCETYPE::RELICSOURCE:
            return QList<QVariant>();
        default:
            return QList<QVariant>();
    }
}

QStringList Mod::getDetails() const
{

}

const QString &Mod::getName() const
{
    return name_;
}

const DROPTYPE &Mod::getType() const
{
    return type_;
}

const QString &Mod::getId() const
{
    return id_;
}

}   // Data
}   // Program

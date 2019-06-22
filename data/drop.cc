#include "drop.hh"

namespace Program {
namespace Data {
Drop::Drop(const QString &id, const QString &name, const DROPTYPE &type) :
    id_{id}, name_{name}, type_{type}
{

}
QList<QVariant> Drop::getSources(SOURCETYPE type)
{
    if(!sources_.contains(type)) {
        return QList<QVariant>();
    }
    auto tmpData{sources_.value(type)};
    QList<QVariant> tmp;

    for (auto source : tmpData) {
        tmp.append(source->getData());
    }
    return tmp;

}

bool Drop::addSource(std::shared_ptr<Source> loc, SOURCETYPE type)
{

    sources_[type].append(loc);
    return true;
}

const QString &Drop::getName() const
{
    return name_;
}

const DROPTYPE &Drop::getType() const
{
    return type_;
}

const QString &Drop::getId() const
{
    return id_;
}

int Drop::getSourceCount(SOURCETYPE type) const
{
    if(!sources_.contains(type)) {
        return 0;
    }
    return sources_.value(type).size();
}


}
}

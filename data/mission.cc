#include "mission.hh"
namespace Program {
namespace Data {

Mission::Mission()
{

}

QVariant Mission::getData()
{
    QStringList tmp;
    tmp << name_;
    return QVariant(tmp);
}

const QString &Mission::getName() const
{
    return name_;
}

const SOURCETYPE &Mission::getType() const
{
    return type_;
}

const QString &Mission::getId() const
{
    return id_;
}
}}

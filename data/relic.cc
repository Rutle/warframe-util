#include "relic.hh"
namespace Program {
namespace Data {
Relic::Relic() {

}
Relic::Relic(const QString &id, const QString &name, const ENTITY &type,
             const QString &tier):
    id_{id}, name_{name}, type_{type}, tier_{tier}
{

}
/*
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

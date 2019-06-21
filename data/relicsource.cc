#include "relicsource.hh"
namespace Program {
namespace Data {
RelicSource::RelicSource()
{

}

RelicSource::RelicSource(const QString &ch, const QString &rarity,
                               const QString &id, const QString &name,
                               const QString &tier, SOURCETYPE type):
    chance_{ch}, rarity_{rarity}, id_{id}, name_{name}, tier_{tier},
    type_{type}
{

}

QVariant RelicSource::getData()
{
    QStringList tmp;
    tmp << name_;
    tmp << tier_;
    tmp << rarity_;
    tmp << chance_;

    return QVariant(tmp);
}
}}

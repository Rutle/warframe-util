#include "relicsource.hh"
namespace Program {
namespace Data {
RelicSource::RelicSource()
{

}

Data::RelicSource::RelicSource(const QString &ch, const QString &rarity,
                               const QString &id, const QString &name,
                               const QString &tier):
    chance_{ch}, rarity_{rarity}, id_{id}, name_{name}, tier_{tier}
{

}

QVariant RelicSource::getData() const
{
    QStringList tmp;
    tmp << name_;
    tmp << tier_;
    tmp << rarity_;
    tmp << chance_;

    return QVariant(tmp);
}
}}

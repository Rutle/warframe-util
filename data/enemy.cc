#include "enemy.hh"
namespace Program {
namespace Data {
Enemy::Enemy()
{

}

Enemy::Enemy(const QString &id, const QString &name, const SOURCETYPE &type,
             const QString &modDropC, const QString &rarity,
             const QString &chance):
    id_{id}, name_{name}, type_{type}, modDropChance_{modDropC}, rarity_{rarity},
    chance_{chance}
{

}

QVariant Enemy::getData()
{
    QStringList tmp;
    tmp << name_;
    tmp << rarity_;
    tmp << chance_;
    return QVariant(tmp);
}
}   // Data
}   // Program

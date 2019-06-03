#include "enemy.hh"
namespace Program {
namespace Data {
Enemy::Enemy()
{

}

Enemy::Enemy(const QString &id, const QString &name, const ENTITY &type):
    DataEntity (id, name, type)
{

}

void Enemy::setStats(const double &modDropChance, const QString &rarity, const int &chance)
{
    modDropChance_ = modDropChance;
    rarity_ = rarity;
    chance_ = chance_;
}
}   // Data
}   // Program

#include "mod.hh"
namespace Program {
namespace Data {

Mod::Mod()
{

}

Mod::Mod(const QString &id, const QString &name, const ENTITY &type):
    DataEntity(id, name, type)
{

}

bool Mod::addEnemy(std::shared_ptr<Enemy> item)
{
    enemies_.append(item);
    return true;
}
/*
bool Mod::addLocation(std::shared_ptr<Location> item)
{

}
*/

int Mod::enemyCount() const
{
    return enemies_.size();
}

QList<QVariant> Mod::getEnemies() const
{
    QList<QVariant> tmp;
    for (auto enemy : enemies_) {
        tmp.append(enemy->getData());
    }
    return tmp;
}


}   // Data
}   // Program

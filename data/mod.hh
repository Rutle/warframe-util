#ifndef MOD_HH
#define MOD_HH

#include "enemy.hh"
//#include "location.hh"

#include "dataentity.hh"
#include <QString>
#include <QVariant>
#include <QVector>
#include <memory>

namespace Program {
namespace Data {

class Mod: public DataEntity
{
    public:
        Mod();
        //~Mod();
        Mod(const QString &id, const QString &name, const ENTITY &type);
        bool addEnemy(std::shared_ptr<Enemy> item);
        //bool addLocation(std::shared_ptr<Location> item);
        int enemyCount() const;
        QList<QVariant> getEnemies() const;
    protected:

    private:
        QVector<std::shared_ptr<Enemy>> enemies_;
        //QVector<std::shared_ptr<Location>> mission_;

};
}   // Data
}   // Program
#endif // MOD_HH

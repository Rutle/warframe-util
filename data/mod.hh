#ifndef MOD_HH
#define MOD_HH

#include "enemy.hh"
#include "types.hh"
#include "drop.hh"

#include <QString>
#include <QVariant>
#include <QVector>
#include <memory>

namespace Program {
namespace Data {

class Mod: public Drop
{
    public:
        Mod();
        Mod(const QString &id, const QString &name, const ENTITY &type);
        bool addEnemy(std::shared_ptr<Enemy> item);
        void addSource(std::shared_ptr<Source> loc, ENTITY type);
        int enemyCount() const;
        QList<QVariant> getSources() const;
        QStringList getDetails() const;
    protected:

    private:
        QVector<std::shared_ptr<Enemy>> enemies_;
        //QVector<std::shared_ptr<Source>> missions_;

};
}   // Data
}   // Program
#endif // MOD_HH

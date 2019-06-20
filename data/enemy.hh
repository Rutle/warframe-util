#ifndef ENEMY_HH
#define ENEMY_HH

#include "source.hh"
#include "types.hh"
#include <QStringList>
#include <QVariant>
namespace Program {
namespace Data {

class Enemy : public Source
{
    public:
        Enemy();
        //~Enemy();
        //const QString &getName() const;
        Enemy(const QString &id, const QString &name, const ENTITY &type);
        void setStats(const double &modDropChance, const QString &rarity,
                      const double &chance);
        QVariant getData() const;

    private:
        double modDropChance_;
        QString rarity_;
        double chance_;
        // Mods []
};
}   // Data
}   // Program

#endif // ENEMY_HH

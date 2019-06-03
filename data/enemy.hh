#ifndef ENEMY_HH
#define ENEMY_HH

#include "dataentity.hh"
namespace Program {
namespace Data {

class Enemy: public DataEntity
{
    public:
        Enemy();
        //~Enemy();
        //const QString &getName() const;
        Enemy(const QString &id, const QString &name, const ENTITY &type);
        void setStats(const double &modDropChance, const QString &rarity,
                      const int &chance);

    private:
        double modDropChance_;
        QString rarity_;
        int chance_;
        // Mods []
};
}   // Data
}   // Program

#endif // ENEMY_HH

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
        Enemy(const QString &id, const QString &name, const SOURCETYPE &type,
              const QString &modDropC, const QString &rarity,
              const QString &chance);
        QVariant getData();
        const QString &getName() const;
        const DROPTYPE &getType() const;
        const QString &getId() const;

    private:
        QString id_;
        QString name_;
        SOURCETYPE type_;
        QString modDropChance_;
        QString rarity_;
        QString chance_;
        // Mods []
};
}   // Data
}   // Program

#endif // ENEMY_HH

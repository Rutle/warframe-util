#ifndef DATAENTITY_HH
#define DATAENTITY_HH


#include <QString>
#include "enemy.hh"
#include "Sourceh"
#include "prime.hh"
#include "mod.hh"
namespace Program {
namespace Data {

class DataEntity
{
    public:
        DataEntity();
        //virtual ~DataEntity();
        const QString &getName() const;
        const ENTITY &getType() const;
        const QString &getId() const;
        void setDrop(std::shared_ptr<Drop> drop);
        bool addEnemySource(std::shared_ptr<Source> loc);
        bool addMissionSource();
        bool addRelicSource();
        const QVector<std::shared_ptr<Source>> &getData(ENTITY type) const;
    protected:

    private:
        QString id_;
        QString name_;
        ENTITY type_;

        std::shared_ptr<Drop> drop_;
        std::shared_ptr<Source> missions_;
        std::shared_ptr<Source> relics_;
        std::shared_ptr<Source> enemies_;




};
}   // Data
}   // Program



#endif // DATAENTITY_HH

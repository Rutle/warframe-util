#ifndef DATAENTITY_HH
#define DATAENTITY_HH


#include <QString>
#include "enemy.hh"
#include "source.hh"
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
        const DROPTYPE &getType() const;
        const QString &getId() const;
        void setDrop(std::shared_ptr<Drop> drop);
        bool addEnemySource(std::shared_ptr<Source> loc);
        bool addMissionSource();
        bool addRelicSource();
        const QVector<std::shared_ptr<Source>> &getData(SOURCETYPE type) const;
    private:
        QString id_;
        QString name_;
        DROPTYPE type_;

        std::shared_ptr<Drop> drop_;
        std::shared_ptr<Source> missions_;
        std::shared_ptr<Source> relics_;
        std::shared_ptr<Source> enemies_;




};
}   // Data
}   // Program



#endif // DATAENTITY_HH

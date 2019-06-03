#ifndef DATAENTITY_HH
#define DATAENTITY_HH

#include <QString>
namespace Program {
namespace Data {

enum ENTITY { Undefined, EnemyType, ModType, LocationType, RelicType };

class DataEntity
{
    public:
        DataEntity();
        //virtual ~DataEntity();
        const QString &getId() const;
        const QString &getName() const;
        const ENTITY &getType() const;
    protected:
        DataEntity(const QString &id,
                   const QString &name,
                   const ENTITY &type);
    private:
        QString id_;
        QString name_;
        ENTITY type_;

};
}   // Data
}   // Program



#endif // DATAENTITY_HH

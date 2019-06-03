#include "dataentity.hh"
namespace Program {
namespace Data {
DataEntity::DataEntity()
{

}

const QString &DataEntity::getId() const
{
    return id_;
}

const QString &DataEntity::getName() const
{
    return name_;
}

const ENTITY &DataEntity::getType() const
{
    return type_;
}

DataEntity::DataEntity(const QString &id, const QString &name,
                       const ENTITY &type): id_{id}, name_{name},
    type_{type}
{

}
}   // Data
}   // Program

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

const DROPTYPE &DataEntity::getType() const
{
    return type_;
}


}   // Data
}   // Program

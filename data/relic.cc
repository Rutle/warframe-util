#include "relic.hh"
namespace Program {
namespace Data {
Relic::Relic() {

}
Relic::Relic(const QString &id, const QString &name, const ENTITY &type):
    DataEntity (id, name, type)
{

}
}   // Data
}   // Program

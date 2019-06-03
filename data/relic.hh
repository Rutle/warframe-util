#ifndef RELIC_HH
#define RELIC_HH

#include "dataentity.hh"

namespace Program {
namespace Data {


class Relic: public DataEntity
{
    public:

        Relic();
        //~Relic();
        Relic(const QString &id, const QString &name, const ENTITY &type,
              const QString &tier);
        void getTier() const;
    private:
        QString tier_;

};

}   // Data
}   // Program
#endif // RELIC_HH

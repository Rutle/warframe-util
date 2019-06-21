#ifndef MISSION_HH
#define MISSION_HH

#include "source.hh"

namespace Program {
namespace Data {

class Mission: public Source
{
    public:
        Mission();
        QVariant getData();
        const QString &getName() const;
        const DROPTYPE &getType() const;
        const QString &getId() const;
};
}
}
#endif // MISSION_HH

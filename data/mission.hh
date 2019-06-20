#ifndef MISSION_HH
#define MISSION_HH

#include "source.hh"

namespace Program {
namespace Data {

class Mission: public Source
{
    public:
        Mission();
        QVariant getData() const;
};
}
}
#endif // MISSION_HH

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
        const SOURCETYPE &getType() const;
        const QString &getId() const;
    private:
        QString name_;
        SOURCETYPE type_;
        QString id_;
};
}
}
#endif // MISSION_HH

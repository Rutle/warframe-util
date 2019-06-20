#ifndef MISC_HH
#define MISC_HH

#include "source.hh"
#include "types.hh"
#include "drop.hh"

#include <QVariant>
#include <QVector>
#include <memory>

namespace Program {
namespace Data {

class Misc: public Drop
{
    public:
        Misc();
        QList<QVariant> getSources() const;
        void addSource(std::shared_ptr<Source> loc, ENTITY type);
        QStringList getDetails() const;
};
}}
#endif // MISC_HH

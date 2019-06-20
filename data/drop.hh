#ifndef DROP_HH
#define DROP_HH

#include "types.hh"
#include "source.hh"
#include <QVariant>
#include <memory>

namespace Program {
namespace Data {

class Drop
{
    public:
        Drop() = default;
        virtual ~Drop() = default;

        virtual QList<QVariant> getSources() const = 0;
        virtual void addSource(std::shared_ptr<Source> loc, ENTITY type) = 0;
        virtual QStringList getDetails() const = 0;

};
}}
#endif // DROP_HH

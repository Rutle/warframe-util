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

        virtual QList<QVariant> getSources(SOURCETYPE type) = 0;
        virtual bool addSource(std::shared_ptr<Source> loc, SOURCETYPE type) = 0;
        virtual QStringList getDetails() const = 0;
        virtual const QString &getName() const = 0;
        virtual const DROPTYPE &getType() const = 0;
        virtual const QString &getId() const = 0;
        virtual int getSourceCount(SOURCETYPE type) const = 0;

};
}}
#endif // DROP_HH

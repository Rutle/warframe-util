#ifndef DROP_HH
#define DROP_HH

#include "types.hh"
#include "source.hh"
#include <QVariant>
#include <QVector>
#include <memory>

namespace Program {
namespace Data {

class Drop
{
    public:
        Drop() = default;
        virtual ~Drop() = default;

        virtual QList<QVariant> getSources(SOURCETYPE type);
        virtual bool addSource(std::shared_ptr<Source> loc, SOURCETYPE type);
        //virtual QStringList getDetails() const = 0;
        virtual const QString &getName() const;
        virtual const DROPTYPE &getType() const;
        virtual const QString &getId() const;
        virtual int getSourceCount(SOURCETYPE type) const;

    // Maybe instead of using interface, add map<type, data> and add implementations
    // to the same functions used by every derived class.
    protected:
        Drop(const QString &id, const QString &name, const DROPTYPE &type);
        QString id_;
        QString name_;
        DROPTYPE type_;
        QMap<SOURCETYPE, QVector<std::shared_ptr<Source>>> sources_;
    private:

};
}}
#endif // DROP_HH

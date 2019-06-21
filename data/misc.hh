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
        QList<QVariant> getSources(SOURCETYPE type);
        bool addSource(std::shared_ptr<Source> loc, SOURCETYPE type);
        QStringList getDetails() const;
        int getSourceCount(SOURCETYPE type) const;
        const QString &getName() const;
        const DROPTYPE &getType() const;
        const QString &getId() const;
    private:
        QString name_;
        QString id_;
        DROPTYPE type_;
        QVector<std::shared_ptr<Data::Source>> missions_;
};
}}
#endif // MISC_HH

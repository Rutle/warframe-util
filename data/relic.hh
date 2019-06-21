#ifndef RELIC_HH
#define RELIC_HH

#include "source.hh"
#include "drop.hh"
#include "types.hh"
#include <QVariant>
#include <QVector>
#include <memory>
namespace Program {
namespace Data {

class Relic: public Drop
{
    public:

        Relic();
        Relic(const QString &id, const QString &name, const DROPTYPE &type,
              const QString &tier);
        QList<QVariant> getSources(SOURCETYPE type);
        bool addSource(std::shared_ptr<Source> loc, SOURCETYPE type);
        QStringList getDetails() const;
        int getSourceCount(SOURCETYPE type) const;
        const QString &getName() const;
        const DROPTYPE &getType() const;
        const QString &getId() const;
    private:
        QString id_;
        QString name_;
        DROPTYPE type_;
        QString tier_;

        QVector<std::shared_ptr<Data::Source>> missions_;

};

}   // Data
}   // Program
#endif // RELIC_HH

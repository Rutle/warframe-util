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
        Relic(const QString &id, const QString &name, const ENTITY &type,
              const QString &tier);
        QList<QVariant> getSources() const;
        void addSource(std::shared_ptr<Source> loc, ENTITY type);
        QStringList getDetails() const;
        //QVariant getData() const;
    private:
        QString id_;
        QString name_;
        ENTITY type_;
        QString tier_;

        QVector<std::shared_ptr<Source>> missions_;

};

}   // Data
}   // Program
#endif // RELIC_HH

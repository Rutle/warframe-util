#ifndef MOD_HH
#define MOD_HH

//#include "enemy.hh"
#include "types.hh"
#include "drop.hh"

#include <QString>
#include <QVariant>
#include <QVector>
#include <memory>

namespace Program {
namespace Data {

class Mod: public Drop
{
    public:
        Mod();
        Mod(const QString &id, const QString &name, const DROPTYPE &type);
        bool addSource(std::shared_ptr<Source> loc, SOURCETYPE type);
        int getSourceCount(SOURCETYPE type) const;
        QList<QVariant> getSources(SOURCETYPE type);
        QStringList getDetails() const;
        const QString &getName() const;
        const DROPTYPE &getType() const;
        const QString &getId() const;
    private:
        QString id_;
        QString name_;
        DROPTYPE type_;
        QVector<std::shared_ptr<Source>> enemies_;
        QVector<std::shared_ptr<Source>> missions_;

};
}   // Data
}   // Program
#endif // MOD_HH

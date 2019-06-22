#ifndef RELICSOURCE_HH
#define RELICSOURCE_HH

#include "source.hh"
#include "types.hh"
#include <QStringList>
#include <QVariant>
namespace Program {
namespace Data {

class RelicSource: public Source
{
    public:
        RelicSource();
        RelicSource(const QString &chance_, const QString &rarity,
                    const QString &id, const QString &name,
                    const QString &tier, SOURCETYPE type);
        QVariant getData();
        const QString &getName() const;
        const SOURCETYPE &getType() const;
        const QString &getId() const;
    private:
        QString chance_;
        QString rarity_;
        QString id_;
        QString name_;
        QString tier_;
        SOURCETYPE type_;
};
}
}
#endif // RELICSOURCE_HH

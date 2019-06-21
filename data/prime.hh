#ifndef PRIME_HH
#define PRIME_HH

#include "types.hh"
#include "drop.hh"
#include "source.hh"
//#include "relicsource.hh"
#include <memory>
#include <QVector>
#include <QVariant>


namespace Program {
namespace Data {

class Prime: public Drop
{
    public:
        Prime();
        Prime(const QString &id, const QString &name, const DROPTYPE &type);
        bool addSource(std::shared_ptr<Source> loc, SOURCETYPE type);
        QList<QVariant> getSources(SOURCETYPE type);
        QStringList getDetails() const;
        int getSourceCount(SOURCETYPE type) const;
        const QString &getName() const;
        const DROPTYPE &getType() const;
        const QString &getId() const;

    private:
        QString id_;
        QString name_;
        DROPTYPE type_;
        struct RelicInfo
        {
            RelicInfo() {chance_ = 0.0; rarity_ = "None";}
            RelicInfo(const QString &ch, const QString &ra):
                chance_{ch}, rarity_{ra}  {}
            QString chance_;
            QString rarity_;
            QString id_;
            QString name_;
            QString tier_;

        };
        //QVector<RelicInfo> relics_;
        QVector<std::shared_ptr<Data::Source>> relics_;

};
}

}
#endif // PRIME_HH

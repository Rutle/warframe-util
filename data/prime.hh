#ifndef PRIME_HH
#define PRIME_HH

#include "types.hh"
#include "drop.hh"
#include <memory>
#include <QVector>
#include <QVariant>


namespace Program {
namespace Data {

class Prime: public Drop
{
    public:
        Prime();
        void addSource(std::shared_ptr<Source> loc, ENTITY type);
        int getRelicCount() const;
        QList<QVariant> getSources() const;
        QStringList getDetails() const;
    protected:

    private:
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
        QVector<Data::Source> relics_;

};
}

}
#endif // PRIME_HH

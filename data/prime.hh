#ifndef PRIME_HH
#define PRIME_HH

#include "relic.hh"
#include "dataentity.hh"
#include <memory>
#include <QVector>


namespace Program {
namespace Data {

class Prime : public DataEntity
{
    public:
        Prime();
        Prime(const QString &id, const QString &name, const ENTITY &type);
        void addRelic(std::shared_ptr<Relic> relic, const double &chance,
                      const QString &rarity);
        bool operator==(const Prime& other) const;
        int getRelicCount() const;
    protected:

    private:
        // < Relic ,< chance, rarity > >

        struct RelicInfo
        {
            RelicInfo() {relic_ = nullptr; chance_ = 0.0; rarity_ = "None";}
            RelicInfo(std::shared_ptr<Relic> re, const double &ch,
                      const QString &ra): relic_{re},
                chance_{ch}, rarity_{ra}  {}
            std::shared_ptr<Relic> relic_;
            double chance_;
            QString rarity_;

        };
        QVector<RelicInfo> relics_;

};
}

}
#endif // PRIME_HH

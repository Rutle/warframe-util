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
    private:
        // < Relic ,< chance, rarity > >
        struct info
        {
            double chance_;
            QString rarity_;
        };
        QVector<std::pair<std::shared_ptr<Relic>, info>> relics_;

};
}

}
#endif // PRIME_HH

#include "prime.hh"
namespace Program {
namespace Data {


Prime::Prime()
{

}

Program::Data::Prime::Prime(const QString &id, const QString &name,
                            const Program::Data::ENTITY &type) :
    DataEntity (id, name, type)
{

}

void Prime::addRelic(std::shared_ptr<Relic> relic, const double &chance, const QString &rarity)
{
    //relics_.append(relic);
    info tmp;
    tmp.chance_ = chance;
    tmp.rarity_ = rarity;
    auto pa = std::make_pair(relic, tmp);
    relics_.append(pa);

}
} // Data
} // Program

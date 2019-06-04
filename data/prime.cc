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
    relics_.append(RelicInfo(relic, chance, rarity));

}

bool Prime::operator==(const Prime &other) const
{
    if(this->getId()==(other.getId()))
    {
       return true;
    }
    return false;

}

int Prime::getRelicCount() const
{
    return relics_.size();
}

} // Data
} // Program

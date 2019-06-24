#ifndef TYPES_HH
#define TYPES_HH

#include <QMap>
namespace Program {
namespace Data {

enum class DROPTYPE { UNDEFINED, MODDROP, RELICDROP, PRIMEDROP, MISCDROP };

enum class SOURCETYPE { UNDEFINED, ALLSOURCE, MISSIONSOURCE, ENEMYSOURCE,
                        RELICSOURCE };

const QMap<QString, SOURCETYPE> MODDROPSOURCES{
    {"enemy", SOURCETYPE::ENEMYSOURCE}, {"mission", SOURCETYPE::MISSIONSOURCE}
};

const QMap<QString, SOURCETYPE> RELICDROPSOURCES{
    {"mission", SOURCETYPE::MISSIONSOURCE}
};
const QMap<QString, SOURCETYPE> PRIMEDROPSOURCES{
    {"relic", SOURCETYPE::RELICSOURCE}
};
const QMap<QString, SOURCETYPE> MISCDROPSOURCES{
    {"enemy", SOURCETYPE::ENEMYSOURCE}, {"mission", SOURCETYPE::MISSIONSOURCE}
};
}
}
#endif // TYPES_HH

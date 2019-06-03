#include "misc.hh"


void Program::sortMods(QVector<Program::Data::Mod> &data)
{
    std::sort(data.begin(), data.end(), compMod);
}


bool Program::compMod(const Program::Data::Mod &first,
                      const Program::Data::Mod &second)
{
    return first.getName() < second.getName();
}

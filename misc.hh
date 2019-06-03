#ifndef MISC_HH
#define MISC_HH

//#include <dataentity.hh>
#include "mod.hh"
#include <QVector>
namespace Program {
void sortMods(QVector<Data::Mod> &data);
bool compMod(const Data::Mod &first, const Data::Mod &second);
}



#endif // MISC_HH

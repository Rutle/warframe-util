#ifndef PROGRAMMODELINTERFACE_HH
#define PROGRAMMODELINTERFACE_HH

#include "datareaderinterface.hh"
#include "mod.hh"
#include "prime.hh"
#include "drop.hh"
//#include "dataentity.hh"
#include <QStringList>
namespace Program {
namespace Interface {

class ProgramModelInterface {
    public:
        ProgramModelInterface() = default;
        virtual ~ProgramModelInterface() = default;

        virtual void setReader(DataReaderInterface *reader) = 0;

        virtual bool readData(QString &msg) = 0;

        virtual const QVector<std::shared_ptr<Data::Drop>> &getModData() = 0;

        virtual const QVector<std::shared_ptr<Data::Drop>> &getPrimeData() = 0;

        // Categories selected
        virtual const QStringList& getSelectedCats() const = 0;


};
}   // Interface
}   // Program

#endif // PROGRAMMODELINTERFACE_HH

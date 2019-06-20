#ifndef PROGRAMMODELINTERFACE_HH
#define PROGRAMMODELINTERFACE_HH

#include "datareaderinterface.hh"
#include "mod.hh"
#include "prime.hh"
#include "dataentity.hh"
#include <QStringList>
namespace Program {
namespace Interface {

class ProgramModelInterface {
    public:
        ProgramModelInterface() = default;
        virtual ~ProgramModelInterface() = default;

        virtual void setReader(DataReaderInterface *reader) = 0;

        virtual bool readData(QString &msg) = 0;

        virtual std::shared_ptr<QVector<Data::Mod>> getModData() const = 0;

        virtual std::shared_ptr<QVector<std::shared_ptr<Data::Prime>>> getPrimeData() const = 0;

        // Categories selected
        virtual const QStringList& getSelectedCats() const = 0;


};
}   // Interface
}   // Program

#endif // PROGRAMMODELINTERFACE_HH

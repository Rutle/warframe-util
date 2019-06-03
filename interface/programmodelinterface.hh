#ifndef PROGRAMMODELINTERFACE_HH
#define PROGRAMMODELINTERFACE_HH

#include "datareaderinterface.hh"
#include "mod.hh"
#include <QStringList>
namespace Program {
namespace Interface {

class ProgramModelInterface {
    public:
        ProgramModelInterface() = default;
        virtual ~ProgramModelInterface() = default;

        virtual void setReader(DataReaderInterface *reader) = 0;

        virtual bool readData(QString &msg) = 0;

        virtual const QVector<Data::Mod> &getMods() = 0;

        virtual bool searchMods(const QString &searchParameter,
                                 QVector<Data::Mod> &container) const = 0;
        virtual std::shared_ptr<QVector<Data::Mod>> getModData() const = 0;


};
}   // Interface
}   // Program

#endif // PROGRAMMODELINTERFACE_HH

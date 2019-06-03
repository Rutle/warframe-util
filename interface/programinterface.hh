#ifndef PROGRAMINTERFACE_HH
#define PROGRAMINTERFACE_HH

#include "programmodelinterface.hh"
#include "datareaderinterface.hh"

namespace Program {
namespace Interface {

class ProgramInterface {
    public:
        ProgramInterface() = default;
        virtual ~ProgramInterface() = default;

        //virtual void searchChannel(QStackedWidget *qStack, QString channel) = 0;

        //virtual void closeProgram() = 0;
        virtual ProgramModelInterface *getModel() = 0;
        virtual void setModel(ProgramModelInterface *model) = 0;
        virtual void setReader(DataReaderInterface *reader) = 0;
        virtual void setUp() = 0;

    private:
};
}   // Interface
}   // Program

#endif // PROGRAMINTERFACE_HH

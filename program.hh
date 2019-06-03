#ifndef PROGRAM_HH
#define PROGRAM_HH

#include "programinterface.hh"
//#include "programmodelinterface.hh"
//#include "datareaderinterface.hh"
#include "mainwindow.hh"

namespace Program {
class Program: public Interface::ProgramInterface
{
    public:
        Program();
        ~Program();

        Interface::ProgramModelInterface *getModel();
        void setModel(Interface::ProgramModelInterface *model);
        void setReader(Interface::DataReaderInterface *reader);
        void show();
        void setUp();
    private:
        Interface::ProgramModelInterface *model_;
        MainWindow *mainUi_;

};
} // Program
#endif // PROGRAM_HH

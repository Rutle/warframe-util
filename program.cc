#include "program.hh"
#include "programmodel.hh"

#include <QDebug>

namespace Program {

Program::Program():
    model_{nullptr}
{
    mainUi_ = new MainWindow;
}

Program::~Program()
{
    delete model_;
    mainUi_->close();
}

void Program::show()
{
    mainUi_->show();

}

void Program::setUp()
{
    QString msg{"Onnistu1."};
    if(!model_->readData(msg)) {
        qDebug() << "Read data failed with message: " << msg;
    }
    mainUi_->setProgram(this);
    mainUi_->updateData();
}

Interface::ProgramModelInterface *Program::Program::getModel()
{
    return model_;
}

void Program::setModel(Interface::ProgramModelInterface *model)
{
    model_ = model;
}

void Program::setReader(Interface::DataReaderInterface *reader)
{
    model_->setReader(reader);
}
} // Program

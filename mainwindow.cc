#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "searchlistdelegate.hh"
#include "searchproxymodel.hh"
#include <QStandardItemModel>
#include <QStackedWidget>
#include <QObject>
#include <QComboBox>

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    program_{nullptr}
{

    ui->setupUi(this);

    //QObject::connect(ui->catComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
    //                 ui->searchStackedWidget, &QStackedWidget::setCurrentIndex);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProgram(Program::Interface::ProgramInterface *program)
{
    program_ = program;
}


void MainWindow::updateData() // fetchData
{
    if(program_->getModel()->getModData() != nullptr) {

        for (auto cat : program_->getModel()->getSelectedCats()) {
            //Program::SearchListDelegate *delegate{new Program::SearchListDelegate()};
            if (cat == "Mods") {
                QListView *tmp{new QListView()};
                Program::SearchProxyModel *filterModel{new Program::SearchProxyModel(tmp)};
                //std::make_shared<Program::SearchProxyModel>(filterModel);
                //qDebug() << "Mods";
                Program::SearchListModel *model{
                    new Program::SearchListModel(
                                program_->getModel()->getModData(), tmp)};
                //catTOmodel_.insert("Mods", model);
                ui->catComboBox->addItem("Mods");
                filterModel->setSourceModel(model);

                tmp->setModel(filterModel);
                comboCats_.insert("Mods", filterModel);
                searchListViews_.insert("Mods", tmp);
                ui->searchStackedWidget->addWidget(searchListViews_.value("Mods"));
            } else if(cat == "Primes") {
                //qDebug() << "Primes";
                QListView *tmp{new QListView()};
                Program::SearchProxyModel *filterModel{new Program::SearchProxyModel(tmp)};
                Program::SearchListModel *model{
                    new Program::SearchListModel(
                                program_->getModel()->getPrimeData(), tmp)};
                //catTOmodel_.insert("Primes", model);
                ui->catComboBox->addItem("Primes");
                //qDebug() << "End primes";
                filterModel->setSourceModel(model);
                filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
                tmp->setModel(filterModel);
                comboCats_.insert("Primes", filterModel);
                searchListViews_.insert("Primes", tmp);
                ui->searchStackedWidget->addWidget(searchListViews_.value("Primes"));
            }
        }
        setSignals();

    }
    //Program::SearchListModel *model{new Program::SearchListModel(program_->getModel()->getModData(), ui->modListView)};
    //my_program::widgets::TopGamesListDelegate *delegate{new my_program::widgets::TopGamesListDelegate()};
    //ui->modListView->setModel(model);
    //topGamesList->setItemDelegate(delegate);
    //ui->modListView->setVisible(true);
    //topGamesList->setStyleSheet("QListView {background-color: transparent;}");

    //QObject::disconnect(ui->searchEdit, &QLineEdit::textChanged,
    //                   nullptr, nullptr);
    //
    //QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
    //                 [=](const QString &newValue){
    //    searchText(newValue);
    //    qDebug() << newValue;
    //    });


    //updateSignal();
}

void MainWindow::setSignals()
{
    QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
                     [=](const QString &newValue){
                         comboCats_.value("Mods")->setFilterRegExp(
                                     QRegExp(newValue, Qt::CaseInsensitive));
                         });

    QObject::connect(ui->catComboBox,
                     static_cast<void(QComboBox::*)(const QString &)>(
                         &QComboBox::currentIndexChanged),
                     [=](const QString &text1){
        ui->searchStackedWidget->setCurrentIndex(
                    ui->catComboBox->currentIndex());
        ui->searchEdit->clear();

        QObject::disconnect(ui->searchEdit, &QLineEdit::textChanged,
                               nullptr, nullptr);

        QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
                         [=](const QString &newValue){
            comboCats_.value(text1)->setFilterRegExp(
                        QRegExp(newValue, Qt::CaseInsensitive));

        });

    });
}


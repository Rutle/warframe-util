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
            QListView *tmp{new QListView()};
            Program::SearchProxyModel *filterModel{new Program::SearchProxyModel(tmp)};
            Program::SearchListModel *model = nullptr;
            if (cat == "Mods") {
                model = new Program::SearchListModel(
                            program_->getModel()->getModData(), tmp);
            } else if(cat == "Primes") {
                model = new Program::SearchListModel(
                                program_->getModel()->getPrimeData(), tmp);
            }
            ui->catComboBox->addItem(cat);
            filterModel->setSourceModel(model);
            filterModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
            tmp->setModel(filterModel);
            tmp->setSelectionMode(QAbstractItemView::SingleSelection);
            comboCats_.insert(cat, filterModel);
            searchListViews_.insert(cat, tmp);
            ui->searchStackedWidget->addWidget(searchListViews_.value(cat));
            // Connect clicked/selected item signal to function to handle
            // data display on right side of the QListView.
            QObject::connect(tmp, &QListView::clicked,
                             [=](const QModelIndex &index){
                //QModelIndex itemIdx = searchListViews_.value(text1)->currentIndex();
                QList<QVariant> tmp(index.data(Qt::UserRole).toList());
                qDebug() << tmp.at(0).toStringList().at(0); // First enemy that drops the mod.



            });
        }
        setSignals();

    }
}

void MainWindow::setSignals()
{
    /*
    // Connect signal from search field to filter slot on filter model.
    QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
                     [=](const QString &newValue){
                         comboCats_.value("Mods")->setFilterRegExp(
                                     QRegExp(newValue, Qt::CaseInsensitive));
                         });
                         */
    // Connect combobox' selected text signal to switch the page on
    // stacked widget to the selected category.
    QObject::connect(ui->catComboBox,
                     static_cast<void(QComboBox::*)(const QString &)>(
                         &QComboBox::currentIndexChanged),
                     [=](const QString &text1){
        ui->searchStackedWidget->setCurrentIndex(
                    ui->catComboBox->currentIndex());
        ui->searchEdit->clear();
        // Reset the signal
        QObject::disconnect(ui->searchEdit, &QLineEdit::textChanged,
                               nullptr, nullptr);
        // Connect the signal to correct filter model's slot.
        QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
                         [=](const QString &newValue){
            comboCats_.value(text1)->setFilterRegExp(
                        QRegExp(newValue, Qt::CaseInsensitive));

        });



    });
}


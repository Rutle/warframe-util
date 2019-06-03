#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "modslistmodel.hh"
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

void MainWindow::searchText(const QString &text)
{

    //QAbstractItemModel *model = comboCats_.value(ui->catComboBox->currentText())->model();
    //model->set
    /*
    QAbstractItemModel *model = comboCats_.value(ui->catComboBox->currentText())->model();
    QModelIndexList list = model->match(model->index(0, 0), Qt::DisplayRole, QVariant::fromValue(text), -1, Qt::MatchContains);
    comboCats_.value(ui->catComboBox->currentText())->selectionModel()->clear();
    foreach(QModelIndex modelIndex, list)
        comboCats_.value(ui->catComboBox->currentText())->selectionModel()->select(modelIndex, QItemSelectionModel::Select);
    // Käytä item delegatea piiloittamaan https://forum.qt.io/topic/87374/hide-an-item-delegate-in-a-listview/4
    */
}
void MainWindow::updateData()
{

    if(program_->getModel()->getModData() != nullptr) {
        QListView *tmp{new QListView()};
        Program::ModsListModel *model{new Program::ModsListModel(program_->getModel()->getModData(),
                                                                 tmp)};
        Program::SearchProxyModel *filterModel{new Program::SearchProxyModel(tmp)};

        Program::SearchListDelegate *delegate{new Program::SearchListDelegate()};

        filterModel->setSourceModel(model);
        tmp->setModel(filterModel);
        tmp->setItemDelegate(delegate);
        ui->searchStackedWidget->addWidget(tmp);
        ui->catComboBox->addItem("Mods");
        comboCats_.insert("Mods", filterModel);
        QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
                                          [=](const QString &newValue){
                             filterModel->setFilterRegExp(QRegExp(newValue));
                             });
    }
    //Program::ModsListModel *model{new Program::ModsListModel(program_->getModel()->getModData(), ui->modListView)};
    //my_program::widgets::TopGamesListDelegate *delegate{new my_program::widgets::TopGamesListDelegate()};
    //ui->modListView->setModel(model);
    //topGamesList->setItemDelegate(delegate);
    //ui->modListView->setVisible(true);
    //topGamesList->setStyleSheet("QListView {background-color: transparent;}");
    QObject::connect(ui->catComboBox, static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
                     [=](const int &newValue){
        ui->searchStackedWidget->setCurrentIndex(newValue);
        });
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


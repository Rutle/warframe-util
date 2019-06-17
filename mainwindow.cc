#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "searchlistdelegate.hh"
#include "searchproxymodel.hh"
#include <QStandardItemModel>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QStringListModel>
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
                             this, &MainWindow::displaySelectedTest);
            /*
            QObject::connect(tmp, &QListView::clicked,
                             [=](const QModelIndex &index){
                //QModelIndex itemIdx = searchListViews_.value(text1)->currentIndex();
                QList<QVariant> tmp(index.data(Qt::UserRole).toList());
                qDebug() << tmp.at(0).toStringList().at(0); // First enemy that drops the mod.



                });*/
        }
        setSignals();

    }
}

void MainWindow::displaySelected(const QModelIndex &index)
{
    QList<QVariant> tmp(index.data(Qt::UserRole).toList());
    qDebug() << tmp.at(0).toStringList().at(0); // First enemy that drops the mod.
    // Instead of using layout I could take advantage of QListView here and
    // add sorting etc.
    QWidget *baseWidget{new QWidget};
    QVBoxLayout *baseLayout{new QVBoxLayout};
    if (ui->catComboBox->currentText() == "Mods") {
        //QScrollArea *baseScrollArea{new QScrollArea};
        QGridLayout *labelLayout{new QGridLayout};
        QLabel *drop{new QLabel("Drop Location:")};
        drop->setContentsMargins(0, 0, 0, 5);
        QLabel *chance{new QLabel("Drop Chance:")};
        chance->setContentsMargins(0, 0, 0, 5);
        QLabel *rarity{new QLabel("Rarity:")};
        rarity->setContentsMargins(0, 0, 0, 5);
        labelLayout->addWidget(drop, 0, 0);
        labelLayout->addWidget(chance, 0, 1);
        labelLayout->addWidget(rarity, 0, 2);
        QFrame *line{new QFrame};
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setContentsMargins(0, 0, 0, 0);
        labelLayout->addWidget(line, 1, 0, 1, 3);
        //labelLayout->setSpacing(0);
        labelLayout->setVerticalSpacing(1);
        //baseFormLayout->setContentsMargins(0, 0, 0, 0);
        for (int idx = 0; idx < tmp.size(); ++idx) {
            QStringList sl{tmp.at(idx).toStringList()};
            QLabel *name{new QLabel(sl.at(0))};
            name->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Minimum);
            name->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            name->setMinimumHeight(20);
            //name->setMaximumHeight(30);
            name->setContentsMargins(0, 0, 0, 0);

            QLabel *chance{new QLabel(sl.at(2))};
            chance->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Minimum);
            chance->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            chance->setMinimumHeight(20);
            //name->setMaximumHeight(30);
            chance->setContentsMargins(0, 0, 0, 0);
            QLabel *rarity{new QLabel(sl.at(1))};
            rarity->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Minimum);
            rarity->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            rarity->setMinimumHeight(20);
            //name->setMaximumHeight(30);
            rarity->setContentsMargins(0, 0, 0, 0);


            labelLayout->addWidget(name, idx+2, 0);
            labelLayout->addWidget(chance, idx+2, 1);
            labelLayout->addWidget(rarity, idx+2, 2);
        }
        /*
        for (auto data : tmp) {
            qDebug() << data;
            QStringList sl{data.toStringList()};
            QLabel *eka{new QLabel(sl.at(0))};
            QLabel *toka{new QLabel(sl.at(1))};
            baseFormLayout->addWidget(eka);
            baseFormLayout->addWidget(toka);
        }*/
        QWidget *formWidget{new QWidget};
        formWidget->setLayout(labelLayout);
        baseLayout->addWidget(formWidget);
        QWidget *spacer{new QWidget};
        spacer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        baseLayout->addWidget(spacer);
        baseWidget->setLayout(baseLayout);



        //formWidget->setLayout(baseFormLayout);
        //baseScrollArea->setWidget(formWidget);
        //QLayoutItem *child;
        //while ((child = ui->resultHL->takeAt(1)) != nullptr) {
        //    delete child;
        //}
        //baseLayout->addWidget(baseScrollArea);
        //baseWidget->setLayout(baseLayout);
        QWidget *tt{ui->resultSA->takeWidget()};
        tt->deleteLater();
        ui->resultSA->setWidget(baseWidget);
        //ui->resultHL->insertWidget(1, baseScrollArea);
    }

}

void MainWindow::displaySelectedTest(const QModelIndex &index)
{
    QWidget *tt{ui->resultSA->takeWidget()};
    tt->deleteLater();

    QWidget *baseWidget{new QWidget};
    QVBoxLayout *baseLayout{new QVBoxLayout};
    index.model();
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


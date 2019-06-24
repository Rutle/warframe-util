#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "searchlistdelegate.hh"
#include "searchproxymodel.hh"
#include "widgetfactory.hh"
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
    resultModel_ = new QStandardItemModel(0, 3, this);
    QSortFilterProxyModel *proxy = new QSortFilterProxyModel(this);
    proxy->setDynamicSortFilter(true);
    resultModel_->setHeaderData(0, Qt::Horizontal, tr("Drop Source:"));
    resultModel_->setHeaderData(1, Qt::Horizontal, tr("Drop Chance:"));
    resultModel_->setHeaderData(2, Qt::Horizontal, tr("Rarity:"));
    proxy->setSourceModel(resultModel_);
    ui->resultView->setModel(proxy);
    ui->resultView->setSortingEnabled(true);
    ui->resultSA->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->resultView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->resultView->setHidden(true);
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
    if(!program_->getModel()->getModData().isEmpty()) {
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
                             this, &MainWindow::displaySelected);
        }
        setSignals();

    }
}

void MainWindow::displaySelected(const QModelIndex &index)
{


    /* For now basic layout solution looks somewhat better. Keeping QTabView
     *  solution in case I want to change.
    QList<QVariant> tmp(index.data(Qt::UserRole).toList());

    //qDebug() << tmp2.value("enemy").toList().at(0).toStringList().at(0);

    qDebug() << tmp2.at(0).toStringList().at(0); // First enemy that drops the mod.
    qDebug() << tmp2.size();
    // Instead of using layout I could take advantage of QListView here and
    // add sorting etc.

    resultModel_->removeRows(0, resultModel_->rowCount(QModelIndex()), QModelIndex());

    //resultModel_->insertRows()
    resultModel_->setHeaderData(0, Qt::Horizontal, tr("Drop Source:"));
    resultModel_->setHeaderData(1, Qt::Horizontal, tr("Drop Chance:"));
    resultModel_->setHeaderData(2, Qt::Horizontal, tr("Rarity:"));
    //resultModel_->setHeaderData(0, Qt::Horizontal, tr("Rarity"));

    for (int idx = 0; idx < tmp2.size(); ++idx) {
        resultModel_->insertRow(idx);
        QStringList sl{tmp2.at(idx).toStringList()};
        qDebug() << sl;
        resultModel_->setData(resultModel_->index(idx, 0, QModelIndex()), sl.at(0));
        resultModel_->setData(resultModel_->index(idx, 1, QModelIndex()), sl.at(1));
        resultModel_->setData(resultModel_->index(idx, 2, QModelIndex()), sl.at(2));
        //resultModel_->setData(resultModel_->index(idx+1, 3, QModelIndex()), sl.at(3));

    }
    qDebug() << resultModel_->rowCount();
    ui->resultView->horizontalHeader()->setStretchLastSection(true);
    ui->resultView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    */

    //QList<QVariant> tmp2(index.data(Qt::UserRole).toMap().value("enemy").toList());
    //QMap<QString, QVariant> tmpMap2(index.data(Qt::UserRole).toMap());
    //QList<QString> keys(index.data(Qt::UserRole).toMap().keys());

    //QWidget *baseWidget{new QWidget};
    //QVBoxLayout *baseLayout{new QVBoxLayout};

    /*
    if (ui->catComboBox->currentText() == "Mods") {
        //QScrollArea *baseScrollArea{new QScrollArea};
        // QWidget *tmp{Program::WidgetFactory::addResultWidget("Mods", tmpMap, bool sort?)}
        QGridLayout *labelLayout{new QGridLayout};
        // Add data based on key in keys:



        QLabel *drop{new QLabel("Drop Source:")};
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
        labelLayout->setVerticalSpacing(1);

        std::sort(tmp2.begin(), tmp2.end(),
                  [](QVariant a, QVariant b){
            return a.toStringList().at(2).toDouble() > b.toStringList().at(2).toDouble() ? true : false;
        });

        for (int idx = 0; idx < tmp2.size(); ++idx) {
            //addRow(Layout, QStringList, type/key)

            QStringList sl{tmp2.at(idx).toStringList()};
            //Program::WidgetFactory::addResultRow(labelLayout, idx+2, sl, key);
            QLabel *name{new QLabel(sl.at(0))};
            name->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Minimum);
            name->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            name->setMinimumHeight(20);
            name->setContentsMargins(0, 0, 0, 0);

            QLabel *chance{new QLabel(sl.at(2))};
            chance->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Minimum);
            chance->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            chance->setMinimumHeight(20);
            chance->setContentsMargins(0, 0, 0, 0);
            QLabel *rarity{new QLabel(sl.at(1))};
            rarity->setSizePolicy(QSizePolicy::Expanding,
                                     QSizePolicy::Minimum);
            rarity->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
            rarity->setMinimumHeight(20);
            rarity->setContentsMargins(0, 0, 0, 0);

            labelLayout->addWidget(name, idx+2, 0);
            labelLayout->addWidget(chance, idx+2, 1);
            labelLayout->addWidget(rarity, idx+2, 2);
        }

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

    } else if (ui->catComboBox->currentText() == "Primes") {

    }*/
    QWidget *tt{ui->resultSA->takeWidget()};
    tt->deleteLater();
    QMap<QString, QVariant> tmpMap(index.data(Qt::UserRole).toMap());
    QWidget *base{Program::WidgetFactory::addResultWidget(
                    ui->catComboBox->currentText(),
                    tmpMap)};
    ui->resultSA->setWidget(base);
    //ui->resultHL->insertWidget(1, baseScrollArea);

}

void MainWindow::setSignals()
{

    // Connect signal from search field to filter slot on filter model.
    QObject::connect(ui->searchEdit, &QLineEdit::textChanged,
                     [=](const QString &newValue){
                         comboCats_.value("Mods")->setFilterRegExp(
                                     QRegExp(newValue, Qt::CaseInsensitive));
                         });

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


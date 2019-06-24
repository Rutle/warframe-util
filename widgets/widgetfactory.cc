#include "widgetfactory.hh"
#include <QVBoxLayout>
#include <QDebug>
namespace Program {

WidgetFactory::WidgetFactory()
{

}

void WidgetFactory::addHeaderRow(QGridLayout *layout, const QStringList &list,
                                 //const Data::SOURCETYPE &type,
                                 const int &rowNumber)
{
    for (int idx = 0; idx < list.size(); ++idx) {
        QLabel *tmpL{new QLabel(list.at(idx))};
        tmpL->setContentsMargins(0, 0, 0, 5);
        layout->addWidget(tmpL, rowNumber, idx);
    }
    QFrame *line{new QFrame};
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(line, 1, 0, 1, list.size());
    layout->setVerticalSpacing(1);
}

void WidgetFactory::addResultRow(QGridLayout *layout, const int &rowNumber,
                                 const QStringList &list)
                                 //const Data::SOURCETYPE &type

{
    for (int idx = 0; idx < list.size(); ++idx) {
        QLabel *tmpL{new QLabel(list.at(idx))};
        tmpL->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Minimum);
        tmpL->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
        tmpL->setMinimumHeight(20);
        tmpL->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(tmpL, rowNumber+2, idx);
    }
    /*
    //QStringList sl{tmp2.at(idx).toStringList()};
    QLabel *name{new QLabel(list.at(0))};
    name->setSizePolicy(QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    name->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    name->setMinimumHeight(20);
    name->setContentsMargins(0, 0, 0, 0);

    QLabel *chance{new QLabel(list.at(2))};
    chance->setSizePolicy(QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    chance->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    chance->setMinimumHeight(20);
    chance->setContentsMargins(0, 0, 0, 0);
    QLabel *rarity{new QLabel(list.at(1))};
    rarity->setSizePolicy(QSizePolicy::Expanding,
                             QSizePolicy::Minimum);
    rarity->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    rarity->setMinimumHeight(20);
    rarity->setContentsMargins(0, 0, 0, 0);

    layout->addWidget(name, rowNumber+2, 0);
    layout->addWidget(chance, rowNumber+2, 1);
    layout->addWidget(rarity, rowNumber+2, 2);
    */
}

QWidget *WidgetFactory::addResultWidget(const QString &selected,
                                        const QMap<QString, QVariant> &data,
                                        bool isSorting)
{

    QList<QString> keys(data.keys());
    QWidget *baseWidget{new QWidget};
    QVBoxLayout *baseLayout{new QVBoxLayout};
    QGridLayout *labelLayout{new QGridLayout};
    int headerIdx{0};
    if (selected == "Mods") {
        for (auto key : keys) {
            WidgetFactory::addHeaderRow(labelLayout, Data::HEADERS.value(key), headerIdx);
            //if (key == "enemy") {
            //    WidgetFactory::addHeaderRow(labelLayout, Data::HEADERS.value(key), 0);
            //}

            QList<QVariant> tmp2(data.value(key).toList());
            for (int idx = 0; idx < tmp2.size(); ++idx) {
                QStringList sl{tmp2.at(idx).toStringList()};
                WidgetFactory::addResultRow(labelLayout, headerIdx+idx+2, sl);

            }
            headerIdx = headerIdx + tmp2.size() - 1 + 2;

        }

    }
    QWidget *formWidget{new QWidget};
    formWidget->setLayout(labelLayout);
    baseLayout->addWidget(formWidget);
    QWidget *spacer{new QWidget};
    spacer->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    baseLayout->addWidget(spacer);
    baseWidget->setLayout(baseLayout);
    return baseWidget;
}

}

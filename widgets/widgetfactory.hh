#ifndef WIDGETFACTORY_HH
#define WIDGETFACTORY_HH

#include "types.hh"
#include <QGridLayout>
#include <QMap>
#include <QLabel>
#include <QWidget>
#include <QVariant>

namespace Program {

class WidgetFactory
{
    public:
        WidgetFactory();

        static void addHeaderRow(QGridLayout *layout, const QStringList &list,
                                 //const Data::SOURCETYPE &type,
                                 const int &rowNumber = 0);

        static void addResultRow(QGridLayout *layout, const int &rowNumber,
                          const QStringList &list );
                          //const Data::SOURCETYPE &type

        static QWidget *addResultWidget(const QString &selected,
                                        const QMap<QString, QVariant> &data,
                                        bool isSorting = false);
};
}
#endif // WIDGETFACTORY_HH

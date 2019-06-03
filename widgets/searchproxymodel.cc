#include "searchproxymodel.hh"
#include <QDebug>
namespace Program {

SearchProxyModel::SearchProxyModel(/*std::shared_ptr<QVector<Program::Data::Mod> > mods,*/
                                   QObject *parent):
    QSortFilterProxyModel(parent)
{
}

bool SearchProxyModel::filterAcceptsRow(int sourceRow,
                                        const QModelIndex &sourceParent) const
{
    QModelIndex index0 = sourceModel()->index(sourceRow, 0, sourceParent);
    QString name{sourceModel()->data(index0).toStringList().at(0)};
    if (name.contains(filterRegExp())) {
        return true;
    }
    return false;

}
}

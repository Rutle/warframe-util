#ifndef SEARCHPROXYMODEL_HH
#define SEARCHPROXYMODEL_HH

#include "mod.hh"
#include <QSortFilterProxyModel>
namespace Program {


class SearchProxyModel : public QSortFilterProxyModel
{
        Q_OBJECT
    public:
        SearchProxyModel(QObject *parent = nullptr);
    protected:
        bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

};
} //Program
#endif // SEARCHPROXYMODEL_HH

#ifndef MODSLISTMODEL_HH
#define MODSLISTMODEL_HH

#include "mod.hh"
#include <QAbstractListModel>

namespace Program {


class ModsListModel : public QAbstractListModel
{
        Q_OBJECT
    public:
        ModsListModel(std::shared_ptr<QVector<Data::Mod>> mods,
                      QObject *parent = nullptr);

        // Header:
        QVariant headerData(int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const;

        // Basic functionality:
        int rowCount(const QModelIndex &parent = QModelIndex()) const;

        QVariant data(const QModelIndex &index,
                      int role = Qt::DisplayRole ) const;
    private:
        std::shared_ptr<QVector<Data::Mod>> mods_;
};
}
#endif // MODSLISTMODEL_HH

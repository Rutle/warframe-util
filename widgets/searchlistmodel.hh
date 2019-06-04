#ifndef SEARCHLISTMODEL_HH
#define SEARCHLISTMODEL_HH

#include "mod.hh"
#include "prime.hh"
#include <QAbstractListModel>

namespace Program {


class SearchListModel : public QAbstractListModel
{
        Q_OBJECT
    public:
        SearchListModel(std::shared_ptr<QVector<Data::Mod>> mods,
                      QObject *parent = nullptr);
        SearchListModel(std::shared_ptr<QVector<Data::Prime>> primes,
                      QObject *parent = nullptr);
        // Header:
        QVariant headerData(int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const;

        // Basic functionality:
        int rowCount(const QModelIndex &parent = QModelIndex()) const;

        QVariant data(const QModelIndex &index,
                      int role = Qt::DisplayRole ) const;
    private:
        QString type_;
        std::shared_ptr<QVector<Data::Mod>> mods_;
        std::shared_ptr<QVector<Data::Prime>> primes_;
};
}
#endif // SearchListModel_HH

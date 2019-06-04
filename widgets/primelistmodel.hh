#ifndef PRIMELISTMODEL_HH
#define PRIMELISTMODEL_HH

#include "prime.hh"
#include <QAbstractListModel>

namespace Program {


class PrimeListModel : public QAbstractListModel
{
        Q_OBJECT
    public:
        PrimeListModel(std::shared_ptr<QVector<Data::Prime>> mods,
                      QObject *parent = nullptr);

        // Header:
        QVariant headerData(int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const;

        // Basic functionality:
        int rowCount(const QModelIndex &parent = QModelIndex()) const;

        QVariant data(const QModelIndex &index,
                      int role = Qt::DisplayRole ) const;
    private:
        std::shared_ptr<QVector<Data::Prime>> primes_;
};
}

#endif // PRIMELISTMODEL_HH

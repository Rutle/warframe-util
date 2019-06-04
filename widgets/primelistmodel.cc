#include "primelistmodel.hh"

namespace Program {

PrimeListModel::PrimeListModel(std::shared_ptr<QVector<Data::Prime>> prime, QObject *parent):
    QAbstractListModel(parent)
{
    primes_ = prime;
}

QVariant PrimeListModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const
{
    if ( role != Qt::DisplayRole ) {
        return QVariant();
    }
    if ( orientation == Qt::Horizontal ) {
        return QString("Column %1").arg(section);
    } else {
        return QString("Row %1").arg(section);
    }
}

int PrimeListModel::rowCount(const QModelIndex &parent) const
{
    return primes_->size();
}

QVariant PrimeListModel::data(const QModelIndex &index, int role) const

{
    if ( !index.isValid() ) {
        // qDebug() << "Data, Index: Invalid";
        return QVariant();
    }
    if ( index.row() < 0 || index.row() >= primes_->size() ) {
        return QVariant();
    }
    if ( role == Qt::DisplayRole ) {
        // Can return QStringList with name, viewers and channels.
        // qDebug() << "DisplayRole: " << role;
        //QString viewers_str{QString::number(mods_->at(index.row()))};
        //QString channels_str{QString::number(games_.at(index.row()).channels)};
        QStringList list;
        list << primes_->at(index.row()).getName();

        //list << viewers_str;
        //list << channels_str;
        return QVariant(list);
    }
    /*
    if ( role == Qt::DecorationRole ) {
        return QVariant(games_.at(index.row()).logo);
    }
    */
    /*
    if ( role == Qt::DecorationRole ) {
        return QVariant(games_.at(index.row()).logo);
    }
    */
    return QVariant();
}

}

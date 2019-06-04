#include "SearchListModel.hh"
#include <QStandardItem>
#include <QDebug>
namespace Program {

SearchListModel::SearchListModel(std::shared_ptr<QVector<Data::Mod>> mods, QObject *parent):
    QAbstractListModel(parent), primes_{nullptr}
{
    mods_ = mods;
    type_ = "Mods";
}

SearchListModel::SearchListModel(std::shared_ptr<QVector<Data::Prime>> primes, QObject *parent):
    QAbstractListModel(parent), mods_{nullptr}
{
    primes_ = primes;
    type_ = "Primes";
    //emit modelReset();
}

QVariant SearchListModel::headerData(int section, Qt::Orientation orientation,
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

int SearchListModel::rowCount(const QModelIndex &parent) const
{
    if(type_ == "Mods") {
        return mods_->size();
    } else if (type_ == "Primes") {
        return primes_->size();
    }

}

QVariant SearchListModel::data(const QModelIndex &index, int role) const

{
    if ( !index.isValid() ) {
        // qDebug() << "Data, Index: Invalid";
        return QVariant();
    }
    /*
    if ( index.row() < 0 || index.row() >= mods_->size() ) {
        return QVariant();
    }
    */
    if ( role == Qt::DisplayRole ) {
        // Can return QStringList with name, viewers and channels.
        // qDebug() << "DisplayRole: " << role;
        //QString viewers_str{QString::number(mods_->at(index.row()))};
        //QString channels_str{QString::number(games_.at(index.row()).channels)};
        QStringList list;
        if(type_ == "Mods") {
            list << mods_->at(index.row()).getName();
        } else if (type_ == "Primes") {
            list << primes_->at(index.row()).getName();
        }

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

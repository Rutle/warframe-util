#include "modslistmodel.hh"
#include <QStandardItem>
namespace Program {

ModsListModel::ModsListModel(std::shared_ptr<QVector<Data::Mod>> mods, QObject *parent):
    QAbstractListModel(parent)
{
    mods_ = mods;
}

QVariant ModsListModel::headerData(int section, Qt::Orientation orientation,
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

int ModsListModel::rowCount(const QModelIndex &parent) const
{
    return mods_->size();
}

QVariant ModsListModel::data(const QModelIndex &index, int role) const

{
    if ( !index.isValid() ) {
        // qDebug() << "Data, Index: Invalid";
        return QVariant();
    }
    if ( index.row() < 0 || index.row() >= mods_->size() ) {
        return QVariant();
    }
    if ( role == Qt::DisplayRole ) {
        // Can return QStringList with name, viewers and channels.
        // qDebug() << "DisplayRole: " << role;
        //QString viewers_str{QString::number(mods_->at(index.row()))};
        //QString channels_str{QString::number(games_.at(index.row()).channels)};
        QStringList list;
        list << mods_->at(index.row()).getName();
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

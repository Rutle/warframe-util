#ifndef SEARCHLISTMODEL_HH
#define SEARCHLISTMODEL_HH

//#include "mod.hh"
//#include "prime.hh"
#include "drop.hh"
#include <QAbstractListModel>

namespace Program {


class SearchListModel : public QAbstractListModel
{
        Q_OBJECT
    public:
        /*
        SearchListModel(std::shared_ptr<QVector<Data::Mod>> mods,
                      QObject *parent = nullptr);
        SearchListModel(std::shared_ptr<QVector<std::shared_ptr<Data::Prime>>> primes,
                      QObject *parent = nullptr);
        */
        SearchListModel(const QVector<std::shared_ptr<Data::Drop>> &drops,
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
        //std::shared_ptr<QVector<Data::Mod>> mods_;
        //std::shared_ptr<QVector<std::shared_ptr<Data::Prime>>> primes_;
        QVector<std::shared_ptr<Data::Drop>> drops_;
        //std::shared_ptr<QVector<std::shared_ptr<Data::Drop>>> drops_;
};
}
#endif // SearchListModel_HH

#ifndef SEARCHLISTDELEGATE_HH
#define SEARCHLISTDELEGATE_HH

#include <QStyledItemDelegate>

namespace Program {


class SearchListDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    public:
        SearchListDelegate(QObject *parent = nullptr);
        //void paint(QPainter *painter, const QStyleOptionViewItem &option,
        //           const QModelIndex &index) const;
        QSize sizeHint(const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;
};
}
#endif // SEARCHLISTDELEGATE_HH

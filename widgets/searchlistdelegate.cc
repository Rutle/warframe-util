#include "searchlistdelegate.hh"
#include <QPainter>
#include <QStyle>
namespace Program {


SearchListDelegate::SearchListDelegate(QObject *parent):
    QStyledItemDelegate(parent)
{

}

// Alloocate each item size in listview. Sadly only useful when list is
// initialized.
QSize SearchListDelegate::sizeHint(const QStyleOptionViewItem &option,
                                   const QModelIndex &index) const
{
    QSize result = QStyledItemDelegate::sizeHint(option, index);
    result.setHeight(50);
    //result.setWidth(160);
    return result;
}
}

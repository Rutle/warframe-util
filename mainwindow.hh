#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "programinterface.hh"
#include "searchproxymodel.hh"
#include "searchlistmodel.hh"

#include <QMainWindow>
#include <QMap>
#include <QListView>
#include <QTableView>
#include <QStandardItemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
        Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void setProgram(Program::Interface::ProgramInterface *program);
        void updateData();

        void displaySelected(const QModelIndex &index);

    private:

        void setSignals();
        Ui::MainWindow *ui;
        Program::Interface::ProgramInterface *program_;
        QMap<QString, QListView *> searchListViews_;
        //QList<std::shared_ptr<Program::SearchProxyModel>> proxies_;
        QMap<QString, Program::SearchProxyModel *> comboCats_;
        //QMap<QString, Program::SearchListModel *> catTOmodel_;
        QStandardItemModel *resultModel_;
        //QTableView *resultView_;
        // https://doc.qt.io/qt-5/qtwidgets-itemviews-chart-mainwindow-cpp.html
        // for QTableModel
};

#endif // MAINWINDOW_HH

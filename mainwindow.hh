#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include "programinterface.hh"
#include "searchproxymodel.hh"
#include <QMainWindow>
#include <QMap>
#include <QListView>


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

        void searchText(const QString &text);
    private:

        Ui::MainWindow *ui;
        Program::Interface::ProgramInterface *program_;
        QMap<QString, Program::SearchProxyModel *> comboCats_;
};

#endif // MAINWINDOW_HH

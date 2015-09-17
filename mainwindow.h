#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <station.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_pushButtonConnect_clicked();

    void on_tableViewStation_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    vector<Station> tabStation;

};

#endif // MAINWINDOW_H

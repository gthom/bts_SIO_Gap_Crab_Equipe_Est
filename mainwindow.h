#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <station.h>
#include <QSqlRelationalTableModel>

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

    void on_tableViewStation_clicked(const QModelIndex &index);

    void on_action_Quitter_2_triggered();

    void afficheStations();
    void afficheBornes();
    void afficheInterventions();

    void on_pushButtonStationAjouter_clicked();

private:
    Ui::MainWindow *ui;

    QSqlRelationalTableModel * modelStations;
    vector<Station> tabStation;

};

#endif // MAINWINDOW_H

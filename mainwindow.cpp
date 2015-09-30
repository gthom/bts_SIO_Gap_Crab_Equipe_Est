/**
 * @author Pierre Bouffier
 * @version 1.0.0
 * @file mainwindow.cpp
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlQuery>


/**
 * @brief MainWindow::MainWindow
 * @param parent
 * Construit le mainwindow principal.
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    afficheStations();
    afficheBornes();
    afficheInterventions();
}

/**
 * @brief MainWindow::~MainWindow
 * Déconstruit le mainwindow principal.
 */

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_pushButtonConnect_clicked
 * Evènement permettant au programme de lister toute les station dans un table view.
 */


/**
 * @brief MainWindow::on_tableViewStation_clicked
 * @param index
 * Evènement qui permet à l'index de la ligne d'être sélectionner afin de lister les bornes.
 */

void MainWindow::on_tableViewStation_clicked(const QModelIndex &index)
{

}

void MainWindow::on_action_Quitter_2_triggered()
{
    close();
}

/**
 * @brief MainWindow::afficheStation
 * Affiche les stations dans le tableViewStation
 */
void MainWindow::afficheStations()
{
    QSqlTableModel *modelStations = new QSqlTableModel();
    modelStations->setTable("STATION");
    modelStations->setEditStrategy(QSqlTableModel::OnFieldChange);
    modelStations->select();

    QSqlQuery queryStations;
    queryStations.exec("SELECT * FROM STATION");
    while(queryStations.next())
    {
        Station* nouvelleStation = new Station(queryStations.value(0).toInt(), queryStations.value(1).toString());
    }

    ui->tableViewStation->setModel(modelStations);
}

/**
 * @brief MainWindow::afficheBornes
 * Affiche les bornes dans le tableViewBorne
 */
void MainWindow::afficheBornes()
{
    QSqlTableModel *modelBornes = new QSqlTableModel();
    modelBornes->setTable("BORNE");
    modelBornes->setEditStrategy(QSqlTableModel::OnFieldChange);
    modelBornes->select();

    QSqlQuery queryBornes;
    queryBornes.exec("SELECT * FROM BORNE");
    ui->tableViewBorne->setModel(modelBornes);
}

/**
 * @brief MainWindow::afficheInterventions
 * Affiche les interventions dans le tableViewIntervention
 */
void MainWindow::afficheInterventions()
{
    QSqlTableModel *modelInterventions = new QSqlTableModel();
    modelInterventions->setTable("INTERVENTION");
    modelInterventions->setEditStrategy(QSqlTableModel::OnFieldChange);
    modelInterventions->select();

    QSqlQuery queryInterventions;
    queryInterventions.exec("SELECT * FROM INTERVENTION");
    ui->tableViewIntervention->setModel(modelInterventions);
}

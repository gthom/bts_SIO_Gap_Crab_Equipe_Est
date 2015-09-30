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

    //affichage des stations
    afficheStations();
    //affichage des bornes
    afficheBornes();
    //affichage des interventions
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

/**
 * @brief MainWindow::on_action_Quitter_2_triggered
 * Ferme l'application
 */
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


    modelStations->setHeaderData(1,Qt::Horizontal,tr("Nom")); //on renomme les colonnes
    modelStations->setHeaderData(2,Qt::Horizontal,tr("Adresse"));
    modelStations->setHeaderData(3,Qt::Horizontal,tr("Latitude"));
    modelStations->setHeaderData(4,Qt::Horizontal,tr("Longitude"));

    while(queryStations.next())
    {
        Station* nouvelleStation = new Station(queryStations.value(0).toInt(), queryStations.value(1).toString());
    }

    ui->tableViewStation->setModel(modelStations);
    ui->tableViewStation->setColumnHidden(0, true);//on masque l'identifiant
    ui->tableViewStation->setColumnWidth(1,100);
    ui->tableViewStation->setColumnWidth(2,150);
    ui->tableViewStation->setColumnWidth(3,100);
    ui->tableViewStation->setColumnWidth(4,100);
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

    modelBornes->setHeaderData(1,Qt::Horizontal,tr("Etat")); //on renomme les colonnes
    modelBornes->setHeaderData(2,Qt::Horizontal,tr("Mise en service"));
    modelBornes->setHeaderData(3,Qt::Horizontal,tr("Derniere revision"));
    modelBornes->setHeaderData(4,Qt::Horizontal,tr("Id Station"));
    modelBornes->setHeaderData(5,Qt::Horizontal,tr("Id TypeBorne"));


    QSqlQuery queryBornes;
    queryBornes.exec("SELECT * FROM BORNE");
    ui->tableViewBorne->setModel(modelBornes);
    ui->tableViewBorne->setColumnHidden(0, true);//on masque l'identifiant
    ui->tableViewBorne->setColumnWidth(1,100);//on change la taille de la colonne
    ui->tableViewBorne->setColumnWidth(2,100);
    ui->tableViewBorne->setColumnWidth(3,100);
    ui->tableViewBorne->setColumnWidth(4,100);
    ui->tableViewBorne->setColumnWidth(5,100);
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

    modelInterventions->setHeaderData(1,Qt::Horizontal,tr("Debut")); //on renomme les colonnes
    modelInterventions->setHeaderData(2,Qt::Horizontal,tr("Fin"));
    modelInterventions->setHeaderData(3,Qt::Horizontal,tr("Id Incident"));
    modelInterventions->setHeaderData(4,Qt::Horizontal,tr("Id Technicien"));

    QSqlQuery queryInterventions;
    queryInterventions.exec("SELECT * FROM INTERVENTION");
    ui->tableViewIntervention->setModel(modelInterventions);
    ui->tableViewIntervention->setColumnHidden(0, true);//on masque l'identifiant
    ui->tableViewIntervention->setColumnHidden(0, true);//on masque l'identifiant
    ui->tableViewIntervention->setColumnWidth(1,150);//on change la taille de la colonne
    ui->tableViewIntervention->setColumnWidth(2,150);
    ui->tableViewIntervention->setColumnWidth(3,100);
    ui->tableViewIntervention->setColumnWidth(4,100);
}

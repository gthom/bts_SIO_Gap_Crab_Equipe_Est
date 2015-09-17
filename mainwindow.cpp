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

void MainWindow::on_pushButtonConnect_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("STATION");
    model->setEditStrategy(QSqlTableModel::OnRowChange);
    model->select();

    QSqlQuery query;
    query.exec("SELECT * FROM STATION");
    while(query.next())
    {
        Station* nouvelleStation = new Station(query.value(0).toInt(), query.value(1).toString());
    }

    ui->tableViewStation->setModel(model);
}

/**
 * @brief MainWindow::on_tableViewStation_clicked
 * @param index
 * Evènement qui permet à l'index de la ligne d'être sélectionner afin de lister les bornes.
 */

void MainWindow::on_tableViewStation_clicked(const QModelIndex &index)
{

}

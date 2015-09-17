#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

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
        Station nouvelleStation = new Station(query.value(0).toInt(), query.value(1).toString())
    }

    ui->tableViewStation->setModel(model);
}

void MainWindow::on_action_Quitter_triggered()
{
    close();
}

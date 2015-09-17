#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlTableModel>

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
    QSqlTableModel *model;
    model->setTable("STATION");
    model->setEditStrategy(QSqlTableModel::OnRowChange);

    ui->tableWidget->setModel(model);
}

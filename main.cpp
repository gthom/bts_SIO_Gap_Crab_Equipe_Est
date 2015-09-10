
#include <QApplication>
#include "mainwindow.h"
#include <QSqlDatabase>

int main(int argc, char *argv[])
{

    // Connexion à la base de donnée
    QSqlDatabase * baseBornes;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseBornes = new QSqlDatabase(db);
    baseBornes->setHostName("172.16.63.111");
    baseBornes->setUserName("userBornesEst");
    baseBornes->setDatabaseName("dbBornesEst");
    baseBornes->setPassword("MH12Evc89");
    baseBornes->open();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}

/**
 * @file station.h
 * @name rmagat
 * @date 10/09/2015
 */

#ifndef STATION_H
#define STATION_H
//#include "borne.h"
#include <QString>
#include <QVector>
#include "visite.h"

/**
 * @brief The Station class
 */

class Station
{
private:
    int idStation; //id de la station
    QString libelleEmplacement; //libellé de l'emplacement de la station
    QVector<Borne> lesBornes; //les bornes de la station

public:
    //constructeur de la station
    Station(int s, QString l, QVector<Borne> br);
    //constructeur vide
    Station();
    //retourne l'id de la station
    int getId();
    //retourne le libellé de la station
    QString getLib();
    // retourne une instance de classe Visite recensant toutes les bornes de la station
    // qui nécessitent d'être révisées, ou null s'il n'y a aucune borne à réviser
    Visite getVisiteAFaire();



};

#endif // STATION_H

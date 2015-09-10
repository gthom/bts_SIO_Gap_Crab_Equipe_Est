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



};

#endif // STATION_H

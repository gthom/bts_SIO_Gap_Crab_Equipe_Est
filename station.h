/**
 * @file station.h
 * @name rmagat
 * @date 10/09/2015
 */

#ifndef STATION_H
#define STATION_H
#include "borne.h"
#include <QString>
#include "visite.h"

/**
 * @brief création de la classe Station
 * Private :
 * idStation
 * libelleEmplacement
 * vecteur lesBornes
 * public :
 * construteur de la station
 * constructeur vide
 * getId
 * getLib
 * getVisiteAFaire
 */
class Visite;
class Station
{
private:
    //id de la station
    int idStation;
    //libellé de l'emplacement de la station
    QString libelleEmplacement;
    //les bornes de la station
    vector<Borne> lesBornes;

public:
    //constructeur de la station
    Station(int s, QString l);
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

#endif  //STATION_H

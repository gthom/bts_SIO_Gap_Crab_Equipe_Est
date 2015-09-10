/**
 * @file station.cpp
 * @name rmagat
 * @date 10/09/2015
 */

#include "station.h"

/**
 * @brief Station::Station
 * @param s
 * @param l
 */

Station::Station(int s, QString l)
{
    idStation=s;
    libelleEmplacement=l;
}

void getVisiteAFaire()
{
    //retourne une instance de classe Visite recensant toutes les bornes de la station qui nécessitent d'être révisées,
    //ou null s'il n'y a aucune borne à réviser
    Visite laVisiteAFaire;
    //pour chaque borne du vecteur lesBornes
    foreach(int idBorne, lesBornes)
    {
        //si la borne est à visiter je l'ajoute à laVisiteAFaire
        if(idBorne == p)
        {
            laVisiteAFaire=idBorne;
            //je renvoie laVisiteAFaire
            return laVisiteAFaire;
        }
    }
}

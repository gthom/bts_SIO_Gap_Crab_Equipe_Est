/**
 * @file station.cpp
 * @name rmagat
 * @date 10/09/2015
 */

#include "station.h"
#include "borne.h"
#include "visite.h"

/**
 * @brief Station::Station
 * @param s
 * @param l
 */

Station::Station(int s, QString l, QVector<Borne> br)
{
    idStation=s;
    libelleEmplacement=l;
    lesBornes=br;
}

Station::Station()
{

}


//retourne l'identifiant de la station
/**
 * @brief Station::getId
 * @return
 *
 */
int Station::getId()
{
    return idStation;
}

//retourne le libellé de l'emplacement
QString Station::getLib()
{
    return libelleEmplacement;
}

Visite Station::getVisiteAFaire()
{
    //retourne une instance de classe Visite recensant toutes les bornes de la station qui nécessitent d'être révisées,
    //ou null s'il n'y a aucune borne à réviser
    Visite laVisiteAFaire;
    //pour chaque borne du vecteur lesBornes
    foreach(Borne laBorne, lesBornes)
    {
        //si la borne est à visiter
        if(laBorne.estAReviser())
        {
            //je l'ajoute à laVisiteAFaire
            laVisiteAFaire.addBorne(laBorne);
        }
    }
    //je renvoie laVisiteAFaire
    return laVisiteAFaire;
}

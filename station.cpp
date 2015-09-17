/**
 * @file station.cpp
 * @name rmagat
 * @date 10/09/2015
 */

#include "station.h"
#include "borne.h"

/**
 * @brief Station::Station
 * @param s
 * @param l
 * le constructeur de la station
 */
Station::Station(int s, QString l, QVector<Borne> br)
{
    idStation=s;
    libelleEmplacement=l;
    lesBornes=br;
}

/**
 * @brief Station::Station
 * le constructeur vide
 */
Station::Station()
{

}

/**
 * @brief Station::getId
 * @return l'identifiant de la station
 *
 */
int Station::getId()
{
    return idStation;
}

/**
 * @brief Station::getLib
 * @return le libellé de l'emplacement
 */
QString Station::getLib()
{
    return libelleEmplacement;
}

/**
 * @brief Station::getVisiteAFaire
 * @return une visite à faire
 * quel est l'état de la visite
 * la durée de la visite
 * dans la station concerner
 * et quelle borne
 */
Visite Station::getVisiteAFaire()
{
    //retourne une instance de classe Visite recensant toutes les bornes de la station qui nécessitent d'être révisées,
    //ou null s'il n'y a aucune borne à réviser
    int dureeRevision=0;
    vector<Borne> vb;

    //pour chaque borne du vecteur lesBornes
    foreach(Borne laBorne, lesBornes)
    {
        //si la borne est à visiter
        if(laBorne.estAReviser())
        {
            //je l'ajoute à laVisiteAFaire
            vb.push_back(laBorne);
            dureeRevision+=laBorne.getDureeRevision();
        }
    }
    //je renvoie laVisiteAFaire
    return Visite(this,vb);
}

/*void Station::ajoutDonnee()
{
    //STATION (id, nom, adresseRue, coordLat, coordLong)
    QSqlQuery query("SELECT * FROM Station");

}*/
















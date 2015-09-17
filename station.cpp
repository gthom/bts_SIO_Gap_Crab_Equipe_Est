/**
 * @file station.cpp
 * @name rmagat
 * @date 10/09/2015
 */

#include "station.h"
#include "borne.h"
#include <QSqlQuery>
#include <QDate>

/**
 * @brief Station::Station
 * @param s
 * @param l
 * le constructeur de la station
 */
Station::Station(int s, QString l)
{
    idStation=s;
    libelleEmplacement=l;

    //requête qui va chercher les infos des Bornes dans la base de donnée,
    //et les ajoutes à l'idStation selectionné
    QSqlQuery query;
    query.exec("SELECT * FROM BORNE WHERE idStation = '" + QString::number(idStation) + "'");
    //tant que la requete envoi un résultats
    /*
    while(query.next())
    {

        QString format("yyyy/MM/dd hh:mm:ss");

        int idBorne = query.value(0).toInt();
        QDate dateDerniereRevision = QDate::fromString(query.value(1).toString(), format);
        Borne vb = new Borne(idBorne, dateDerniereRevision, 1);
        vb.push_back(vb);
    }
    */
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

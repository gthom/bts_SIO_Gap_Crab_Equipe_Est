/**
 *  @file borne.cpp
 *  @author tromanin
 *  @date jeudi 3 septembre 2015, 11:11:57
 *  @brief Fichier borne.cpp
 *
 *  Permet de savoir quelles bornes sont à réviser et de connaître la durée de révision.
 */

#include "borne.h"

/**
 *  @brief Borne::Borne
 *  @param i
 *  @param ddr
 *  @param idcu
 *  @param l
 *  @todo récupérer les champs voulus dans la BDD
 */
Borne::Borne(int i, QDate ddr, int idcu, TypeBorne l)
{
    idBorne = i;
    dateDerniereRevision = ddr;
    indiceCompteurUnites = idcu;

    // On récupère dans la BDD les champs suivants : codeTypeBorne, dureeRevision, nbJoursEntreRevisions, nbUnitesEntreRevisions et on les instancie.
    /*QSqlQuery requete;
    requete.exec("SELECT * FROM TYPEBORNE");
    while(requete.next())
    {
        QString codeTypeBorne = requete.value(1).toString();
        int dureeRevision = requete.value(2).toInt();
        int nbJoursEntreRevisions = requete.value(3).toInt();
        int nbUnitesEntreRevisions = requete.value(4).toInt();
    }*/
    //leType = new TypeBorne(QString codeTypeBorne, int dureeRevision, int nbJoursEntreRevisions, int nbUnitesEntreRevisions);
    leType = l;
    dureeRevision = leType.getDureeRevision();
}

/**
 *  @brief Borne::Borne
 *  Constructeur vide
 */
Borne::Borne()
{

}
/**
 *  @brief Borne::getDureeRevision
 *  @return dureeRevision
 *  @todo récupérer la dureeRevision et la retourner.
 *  Nous permet de connaître la durée de révision.
 */
int Borne::getDureeRevision()
{
    return dureeRevision;
}

/**
 *  @brief Borne::estAReviser
 *  @return Retourne vrai lorsque la borne doit être révisée, soit parce que le temps qui sépare deux révisions pour ce type de borne s'est écoulé depuis la date de la dernière révision, soit parce que le nombre d'unités de recharge délivrées par la borne depuis la dernière révision a atteint le seuil établi pour ce type de borne ; retourne faux sinon.
 *  @todo Récupérer la date de la dernière révision, connaître le nombre de jours entre 2 révisions, connaître le nombre d'unités de recharge délivrées depuis la dernière révision, connaître le nombre d'unités entre les révisions, en fonction du type de la borne.
 */
bool Borne::estAReviser()
{        
    // On crée une variable qui reçoit la date du jour
    QDate dateDuJour = QDate::currentDate();
    // On récupère la date de la dernière révision dans la BDD
    QSqlQuery query("SELECT * FROM BORNE");
    int dateDerniereRevision = query.record().value("dateDerniereRevision").toInt();
    QDate dateDerRevision = QDate(2015,9,15); // On définie une date fixe pour l'instant, ensuite il faudra récupérer cette date dans la BDD.

    // On calcule la différence entre 2 dates
    int maDate = dateDerRevision.daysTo(dateDuJour);

    int nbJoursEntreRevisions = 0;
    int indiceCompteurUnites = 0;
    int nbUnitesEntreRevisions = 0;


    if(nbJoursEntreRevisions > maDate)
    {
        return true;
    }
    else
    {
        if(indiceCompteurUnites > nbUnitesEntreRevisions)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}

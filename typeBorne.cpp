/**
 * @date 10 septembre 2015
 * @author Alexia Fontraille
 * @file typeBorne.cpp
 * @version
 * @brief travail sur les type de borne
 */

#include <iostream>
#include "typeBorne.h"

//constructeur
TypeBorne::TypeBorne(QString c, int d, int n, int a)
{
    codeTypeBorne=c;
    dureeRevision=d;
    nbJoursEntreRevisions=n;
    nbUnitesEntreRevisions=a;
}

TypeBorne::TypeBorne()
{
    //constructeur vide
}

//Implémentation
/**
 * @brief retourne la durée en minutes requise
 * pour réaliser la révision sur les bornes de ce type
 * @return
 */
int TypeBorne::getDureeRevision()
{
    return dureeRevision;
}

/**
 * @brief retourne le nombre de jours
 * au dela duquel il faut envisager une révision
 * sur les bornes de ce type
 * @return
 */
int TypeBorne::getNbJoursEntreRevisions()
{
    return nbJoursEntreRevisions;
}

/**
 * @brief retourne le nombre d'unités de recharge
 * au dela duquel il faut envisager une révision
 * sur les bornes de ce type
 * @return
 */
int TypeBorne::getNbUnitesEntreRevisions()
{
    return nbUnitesEntreRevisions;
}

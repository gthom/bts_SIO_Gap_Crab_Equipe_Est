/**
 * @author Alexia Fontraille
 * @file typeBorne.h
 * @date 10 septembre 2015
 */

#include <iostream>
#include <string>
#ifndef TYPEBORNE_H
#define TYPEBORNE_H

class TypeBorne
{

    /**
     * @fn typeBorne
     * Private :
     * dureeRevision
     * nbJoursEntreRevisions
     * nbUnitesEntreRevisions
     * public :
     * getDureeRevision
     *
     */
    public:
        //constructeur
        TypeBorne(string c,int d, int n, int a);
        TypeBorne();

        //Accesseur en lecture

        //retourne la durée en minutes requise pour réaliser la révision sur les bornes de ce type
        int getDureeRevision();
        //retourne le nombre de jours au dela duquel il faut envisager une révision sur les bornes de ce type
        int getNbJoursEntreRevisions();
        //retourne le nombre d'unités de recharge au dela duquel il faut envisager une révision sur les bornes de ce type
        int getNbUnitesEntreRevisions();

    private:
        //durée en minutes requise pour réaliser la révision sur les bornes de ce type
        int dureeRevision;
        //nombre de jours qui séparent deux révisions successives d'une borne de ce type
        int nbJoursEntreRevisions;
        //nombre d'unités de recharges au delà duquel il faut envisager une nouvelle révision
        int nbUnitesEntreRevisions;
        //code du type de la borne
        string codeTypeBorne;
};
#endif // TYPEBORNE_H

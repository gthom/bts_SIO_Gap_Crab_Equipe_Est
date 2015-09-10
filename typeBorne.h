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
     * getNbJoursEntreRevisions
     * getNbUnitesEntreRevisions
     */
    public:

        //constructeur
        TypeBorne(string c,int d, int n, int a);
        TypeBorne();

        //Accesseur en lecture

        /**
         * @brief retourne la durée en minutes requise
         * pour réaliser la révision sur les bornes de ce type
         */
        int getDureeRevision();

        /**
         * @brief retourne le nb de jours
         * au dela duquel il faut envisager une révision
         * sur les bornes de ce type
         */
        int getNbJoursEntreRevisions();

        /**
         * @brief retourne le nb d'unités de recharge
         * au dela duquel il faut envisager une révision
         * sur les bornes de ce type
         */
        int getNbUnitesEntreRevisions();

    private:

        /** @brief durée en minutes pour réaliser la révision
         * sur les bornes de ce type
         */
        int dureeRevision;

        /**
         * @brief nb de jours qui séparent deux révisions successives
         * d'une borne de ce type
         */
        int nbJoursEntreRevisions;

        /**
         * @brief nb d'unités de recharges au dela duquel
         * il faut envisager une nvelle révision
         */
        int nbUnitesEntreRevisions;

        /**
         * @brief code du type de la borne
         */
        string codeTypeBorne;
};
#endif // TYPEBORNE_H

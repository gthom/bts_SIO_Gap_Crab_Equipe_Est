/**
 * @author Alexia Fontraille
 * @file typeBorne.h
 * @date 10 septembre 2015
 * @brief classe TypeBorne
 * @version
 */


#ifndef TYPEBORNE_H
#define TYPEBORNE_H
#include <iostream>
#include <QString>

class TypeBorne
{

    /**
     * @class classe typeBorne
     * @brief classe représente les types de bornes
     * Private :
     * la durée de la révision
     * le nombre de jours entre les révisions
     * le nombre d'unités entre les révisions
     * Public :
     * @fn getDureeRevision
     * @brief retourne la durée en minutes requise
     * pour réaliser la révision sur les bornes de ce type
     * @fn getNbJoursEntreRevisions
     * @brief retourne le nb de jours
     * au dela duquel il faut envisager une révision
     * @fn getNbUnitesEntreRevisions
     * @brief retourne le nb d'unités de recharge
     * au dela duquel il faut envisager une révision
     * sur les bornes de ce type
     */

    public:

        //constructeur
        TypeBorne(QString c,int d, int n, int a);
        TypeBorne();

        //Accesseur en lecture

        /**
         * @fn getDureeRevision
         */
        int getDureeRevision();

        /**
         * @fn getNbJoursEntreRevisions
         */
        int getNbJoursEntreRevisions();

        /**
         * @fn getNbUnitesEntreRevisions
         */
        int getNbUnitesEntreRevisions();

    private:

        /**
         * @brief la durée de la révision
         */
        int dureeRevision;

        /**
         * @brief le nombre de jours entre la révision
         */
        int nbJoursEntreRevisions;

        /**
         * @brief le nombre d'unités entre la révision
         */
        int nbUnitesEntreRevisions;

        /**
         * @brief code du type de la borne
         */
        QString codeTypeBorne;
};
#endif // TYPEBORNE_H

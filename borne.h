#ifndef BORNE_H
#define BORNE_H

/**
 *  @file borne.h
 *  @author tromanin
 *  @date jeudi 3 septembre 2015, 11:11:57
 *  @brief Classe de la Borne.
 *  @class Borne
 */

#include <iostream>
#include <string>
#include <QDate>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include "typeBorne.h"
using namespace std;
class Borne
{
	private:
         /**
         * @brief idBorne, identifiant de la borne (entier)
         */
        int idBorne;

        /**
         * @brief dateDerniereRevision, date de la dernière révision effectuée sur la borne
         */
        QDate dateDerniereRevision;

        /**
         * @brief indiceCompteurUnites
         *  Nombre d'unités de recharge délivrées depuis la dernière révision,
         *  Ce compteur étant remis à 0 à chaque révision.
         */
		int indiceCompteurUnites;

        /**
         * @brief leType
         * @param idBorne
         * @return Retourne le type de la borne
         */
        TypeBorne leType;

	public:
        /**
         * @brief getDureeRevision
         * @return Retourne la durée en minutes requise pour réaliser la révision sur la borne, cette durée étant fonction du type de la borne.
         */
        int getDureeRevision();

        /**
         * @brief estAReviser
         * @return Retourne vrai lorsque la borne doit être révisée, soit parce que le temps qui sépare deux révisions pour ce type de borne s'est écoulé depuis la date de la dernière révision, soit parce que le nombre d'unités de recharge délivrées par la borne depuis la dernière révision a atteint le seuil établi pour ce type de borne ; retourne faux sinon.
         */
		bool estAReviser();

        Borne(int i, QDate ddr, int idcu);
        Borne();
};
#endif // BORNE_H

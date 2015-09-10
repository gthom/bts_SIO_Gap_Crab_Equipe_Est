#ifndef BORNE_H
#define BORNE_H
/*
 * Auteur : tromanin
 * Date de création : jeudi 3 septembre 2015, 11:11:57
 * Rôle : Classe de la Borne.
 * 
 */

#include <iostream>
#include <string>
#include <QDate>
#include "typeBorne.h"
using namespace std;
class Borne
{
	private:
		int idBorne; // Identifiant de la borne (entier)

        	QDate dateDerniereRevision; // Date de la dernière révision effectuée sur la borne

		int indiceCompteurUnites;
		// Nombre d'unités de recharge délivrées depuis la dernière révision,
		// ce compteur étant remis à 0 à chaque révision

		TypeBorne leType; // Le type de la borne

	public:
		int getDureeRevision(); 
		// Retourne la durée en minutes requise pour réaliser la révision sur la borne,
		// cette durée étant fonction du type de la borne

		bool estAReviser();
		// Retourne vrai lorsque la borne doit être révisée, soit parce que le temps qui sépare
		// deux révisions pour ce type de borne s'est écoulé depuis la date de la dernière révision, 
		// soit parce que le nombre d'unités de recharge délivrées par la borne 
		// depuis la dernière révision a atteint le seuil établi pour ce type de borne ; 
		// retourne faux sinon
};

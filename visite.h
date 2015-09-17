/**
 * @file visite.h
 * @date 10 septembre 2015
 * @brief travail sur les visites à une borne
 * @author Martin Reymond
 * @version
 */

#ifndef VISITE_H
#define VISITE_H

#include <string>
#include <vector>
#include "borne.h"
#include "station.h"

using namespace std;
/**
 * @brief création de la classe Station
 * @class Station
 */
class Station;
/**
 * @brief The Visite class
 * @class Visite
 */
class Visite
{
	private :


       /**
        * @var char etat
        * état de la visite : 'p' pour programmée, 'a' pour affectée; 'r' pour réalisée
        */

        char etat;

        /**
         * @brief dureeTotale
         * @var int dureeTotale
         * durée totale en minutes requise pour réaliser l'ensemble des révisions
         * prévues sur les bornes de la station
         */

		int dureeTotale;

        /**
         * @brief laStation
         * la station concernée par la visite
         */

        Station* laStation;

        /**
         * @brief tabBorne
         * collection des bornes de laStation par la visite
         */

		vector<Borne> tabBorne; 

    public :
		

        /**
         * @brief Visite
         * @param ls
         * @param tb
         * constructeur de Visite
         */

        Visite(Station* ls, vector<Borne> tb);

        /**
         * @brief Visite
         * constructeur vide
         */

		Visite();

        /**
         * @brief getDureeTotale
         * @return total
         * retourne la durée totale en minutes requise pour réaliser l'ensemble
         * des révisions prévues sur les bornes de la station
         */

		int getDureeTotale();

        /**
         * @brief getEtat
         * @return etat
         * retourne l'état de la visite
         */

		char getEtat();

        /**
         * @brief changerEtat
         * permet de modifier l'état de la visite
         */

        void changerEtat();

        /**
         * @brief addBorne
         * @param laBorne
         * permet l'ajout d'une borne
         */

        void addBorne(Borne laBorne);

};

#endif // VISITE_H

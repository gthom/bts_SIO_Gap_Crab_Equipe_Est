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
class Station;
//déclaration
class Visite
{
	private :

		//état de la visite : 'p' pour programmée, 'a' pour affectée, 'r' pour réalisée
		char etat;
		// durée totale en minutes requise pour réaliser l'ensemble des révisions 
		// prévues sur les bornes de la station
		int dureeTotale;
		// la station concernée par la visite		
        Station* laStation;
		// la collection des bornes de laStation concernées par la visite
		vector<Borne> tabBorne; 

    public :
		
		// constructeur de Visite
        Visite(Station* ls, vector<Borne> tb);
        // constructeur vide
		Visite();
		// retourne la durée totale en minutes requise pour réaliser l'ensemble
		// des révisions prévues sur les bornes de la station
		int getDureeTotale();
		// retourne l'état de la visite
		char getEtat();
		// retourne l'état de la visite
        void changerEtat();
        // permet l'ajout d'une borne
        void addBorne(Borne laBorne);

};

#endif // VISITE_H

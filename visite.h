/**
 * @file visite.h
 * @date 10 septembre 2015
 * @brief travail sur les visites à une borne
 * @author Martin Reymond
 * @version
 */

#include <string>
#include <vector>
#include "borne.h"
#include "station.h"

using namespace std;

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
		Station laStation; 
		// la collection des bornes de laStation concernées par la visite
		vector<Borne> tabBorne; 

    public :
		
		// constructeur de Visite
		Visite(char e, int d, Station ls, vector<Borne> tb);
		Visite();
		// retourne la durée totale en minutes requise pour réaliser l'ensemble
		// des révisions prévues sur les bornes de la station
		int getDureeTotale();
		// retourne l'état de la visite
		char getEtat();
		// retourne l'état de la visite
        void changerEtat();
        Borne getTabBorne();

};

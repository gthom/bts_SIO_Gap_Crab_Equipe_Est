/**
 * @file technicien.h
 * @author R.Chauveau
 * @date 09 septembre 2015 
 */
#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <iostream>
#include <string>
#include <QString>
#include <vector>
#include "visite.h"
using namespace std;

/** 
 * @class Classe Technicien
 * @brief Classe représentant le technicien
 * Private :
 * matricule du technicien
 * nom du technicien
 * prenom du technicien
 * tabVisite ensemble des visites affectées au technicien
 * Public :
 * constructeur Technicien
 * @fn getTempsOccupe()
 * @brief retourne la durée totale en minutes des visites affectées au technicien
 * @fn affecterVisite (uneVisite Visite)
 * @brief ajoute la visite uneVisite dans les visites affectées au technicien
 * @fn getLesVisites()
 * @brief retourne l'ensemble des visites affectées au technicien
 */
class Technicien
{
	private:
		int matricule; //matricule du technicien
        QString nom; //nom du technicien
        QString prenom; // prénom du technicien
        vector<Visite> lesVisites; //ensemble des visites affectées au technicien
		
	public:
		//constructeur
        Technicien(int m, QString n, QString p, vector<Visite> lv);
		Technicien();

        //fonctions
        // retourne la durée totale en minutes des visites affectées au technicien
		int getTempsOccupe();
        // ajoute la visite uneVisite dans les visites affectées au technicien
        void affecterVisite(Visite uneVisite);
        // retourne l'ensemble des visites affectées au technicien
        vector<Visite> getLesVisites();
};

#endif // TECHNICIEN_H

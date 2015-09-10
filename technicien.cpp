/**
 * @file technicien.cpp
 * @author R.Chauveau
 * @date 09 septembre 2015
 */
#include <iostream>
#include "technicien.h"

//constructeur
Technicien::Technicien(int m, QString n, QString p)
{
    matricule = m;
    nom = n;
    prenom = p;
	
}
Technicien::Technicien()
{
}

// retourne la durée totale en minutes des visites affectées au technicien
int Technicien::getTempsOccupe()
{

}

// ajoute la visite uneVisite dans les visites affectées au technicien
void Technicien::affecterVisite(uneVisite Visite)
{



}

// retourne l'ensemble des visites affectées au technicien
int Technicien::getLesVisites()
{
}

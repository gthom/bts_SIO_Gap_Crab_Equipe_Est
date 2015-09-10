/**
 * @file technicien.cpp
 * @author R.Chauveau
 * @date 09 septembre 2015
 */
#include <iostream>
#include <vector>
#include "technicien.h"
#include "visite.h"

//constructeur
Technicien::Technicien(int m, QString n, QString p, vector lv)
{
    matricule = m;
    nom = n;
    prenom = p;
    lesVisites = tv;
	
}
Technicien::Technicien()
{
}

/**
 * @brief retourne la durée totale en minutes des visites affectées au technicien
 */
int Technicien::getTempsOccupe()
{
    int TotalDureeVisites=0;
    // pour chaque visite affectée au technicien, on additionne la durée
    for(int compteur=0;compteur<lesVisites.size();compteur++)
    {
        TotalDureeVisites+=Visite.getDureeTotale();
    }
    return TotalDureeVisites;
}
/**
 * @brief ajoute la visite uneVisite dans les visites affectées au technicien
 */
void Technicien::affecterVisite(uneVisite Visite)
{
    lesVisites= new * Visite;
}

// retourne l'ensemble des visites affectées au technicien
Visite Technicien::getLesVisites()
{
    return lesVisites;
}

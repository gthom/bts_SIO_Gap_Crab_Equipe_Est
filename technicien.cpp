/**
 * @file technicien.cpp
 * @author R.Chauveau
 * @date 09 septembre 2015
 */
#include <iostream>
#include <vector>
#include "technicien.h"
#include "visite.h"
#include <QSqlQuery>

/**
 * @brief Constructeur
 */
Technicien::Technicien(int m, QString n, QString p, vector<Visite> lv)
{
    matricule = m;
    nom = n;
    prenom = p;
    lesVisites = lv;
	
}
/**
 * @brief Constructeur vide
 */
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
        TotalDureeVisites += lesVisites[compteur].getDureeTotale();
    }
    return TotalDureeVisites;
}
/**
 * @brief ajoute la visite uneVisite dans les visites affectées au technicien
 */
void Technicien::affecterVisite(Visite uneVisite)
{
    lesVisites.push_back(uneVisite);
}

/**
 * @brief retourne l'ensemble des visites affectées au technicien
 */
vector<Visite> Technicien::getLesVisites()
{
    return lesVisites;
}

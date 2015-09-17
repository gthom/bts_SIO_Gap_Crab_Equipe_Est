/**
 * @author Robin Lesieur, Rémi Chauveau
 * @file maintenance.h
 * @date 17/08/15
 * @class Maintenance
 */

#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include "technicien.h"
#include "station.h"
#include <iostream>
#include <QString>
#include <vector>

/**
 * @class Classe Maintenance
 * @brief Classe représentant la maintenance
 * Private :
 * vector<Station> lesStations;
 * vector<Technicien> lesTechniciens;
 * vector<Visite> lesVisites;
 * Public :
 * constructeur maintenance
 * @fn reviser()
 * @brief Etablit l'ensemble des visites à réaliser sur les stations
 * @fn affecterVisites ()
 * @brief Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
 * entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
 * total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.
 */
class Maintenance
{
private:
    vector<Station> lesStations;
    vector<Technicien> lesTechniciens;
    vector<Visite> lesVisites;

public:
    Maintenance(vector<Station> ls, vector<Technicien> lt, vector<Visite> lv);
    Maintenance();

    void reviser (); // Etablit l'ensemble des visites à réaliser sur les stations
    void affecterVisites();// Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
                           // entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
                           // total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.

};

#endif // MAINTENANCE_H

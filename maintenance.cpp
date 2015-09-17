#include "maintenance.h"
#include <iostream>
#include <vector>

/**
 * @brief Constructeur de la classe maintenance
 */
Maintenance::Maintenance(vector<Station> ls, vector<Technicien> lt, vector<Visite> lv)
{
    lesStations = ls;
    lesTechniciens = lt;
    lesVisites = lv;
}

/**
 * @brief Constructeur vide
 */
Maintenance::Maintenance()
{
}

/**
 * @brief Etablit l'ensemble des visites à réaliser sur les stations
 */
void Maintenance::reviser()
{

}

/**
 * @brief Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
 * entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
 * total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.
 */
void Maintenance::affecterVisites()
{

}

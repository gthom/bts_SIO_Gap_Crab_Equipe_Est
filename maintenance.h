/**
 * @author Robin Lesieur
 * @file maintenance.h
 * @date 10/08/15
 * @class Maintenance
 */

#include technicien.h
#include station.h
#ifndef MAINTENANCE_H
#define MAINTENANCE_H

class Maintenance
{
public:
    Maintenance();

    void reviser (); // Etablit l'ensemble des visites à réaliser sur les stations
    void affecterVisites();// Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
                           // entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
                           // total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.
private:
    vector <stations> lesStations;
    vector <techniciens> lesTechniciens;
    vector <visites> lesVisites;
};

#endif // MAINTENANCE_H

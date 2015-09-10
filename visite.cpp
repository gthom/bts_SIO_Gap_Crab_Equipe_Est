/**
 * @file visite.cpp
 * @date 10 septembre 2015
 * @brief travail sur les visites à une borne
 * @author Martin Reymond
 * @version
 */

#include "visite.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


Visite::Visite()
{
}
// ce constructeur valorise tous les attributs privés de la classe Visite, y compris l'état et la
// durée totale de la visite
Visite::Visite(vector<Borne> tb, Station ls)
{
    laStation = ls;
    tabBorne = tb;
    etat = 'p';
    dureeTotale = getDureeTotale();
}

// retourne la durée totale en minutes requise pour réaliser l'ensemble 
// des révisions prévues sur les bornes de la station
int Visite::getDureeTotale()
{
    int total = 0;
    for(int cpt = 0; cpt<tabBorne.size(); cpt++)
    {
        total += tabBorne[cpt].getDureeRevision();

    }
    return total;
}

// retourne l'état de la visite
char Visite::getEtat()
{
    return etat;
}

// modifie l'état de la visite, de 'p' programmée à 'a' affectée, ou de 'a' affectée à 'r' réalisée
void Visite::changerEtat()
{
    if(etat == 'p')
	{
        etat = 'a';
	}
    else
    {
        if(etat =='a')
        {
            etat = 'r';
        }
    }
}

Borne Visite::getTabBorne()
{
    return tabBorne;
}



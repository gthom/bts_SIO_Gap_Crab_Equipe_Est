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

Visite::Visite(char e, int d, Station ls, vector<Borne> tb)
{
	etat=e;
	dureeTotale=d;
	laStation=ls;
	tabBorne=tb;
}

// retourne la durée totale en minutes requise pour réaliser l'ensemble 
// des révisions prévues sur les bornes de la station
int Visite::getDureeTotale()
{
	return dureeTotale;
}

// retourne l'état de la visite
char Visite::getEtat()
{
    return etat;
}

// modifie l'état de la visite, de 'p' programmée à 'a' affectée, ou de 'a' affectée à 'r' réalisée
void Visite::changerEtat()
{
    if(etat =='p')
	{
        etat=='a';
	}
    if(etat =='a')
	{
        etat=='r';
	}
}



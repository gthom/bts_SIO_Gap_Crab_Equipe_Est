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
#include <QSqlQuery>

using namespace std;

/**
 * @brief Visite::Visite
 * constructeur vide de la classe Visite
 */

Visite::Visite()
{
}


/**
 * @brief Visite::Visite
 * @param ls
 * @param t
 * ce construteur valorise tous les attributs privés de la classe Visite, y compris l'état
 * et la durée totale de la visite
 */

Visite::Visite(Station* ls, vector<Borne> tb)
{
    laStation = ls;
    tabBorne = tb;
    etat = 'p';
    dureeTotale = getDureeTotale();
}

/**
 * @brief Visite::getDureeTotale
 * @return total
 * retourne la durée totale en minutes requise pour réaliser l'ensemble
 * des révision prévues sur les bornes de la station
 */

int Visite::getDureeTotale()
{
    int total = 0;
    for(int cpt = 0; cpt<tabBorne.size(); cpt++)
    {
        total += tabBorne[cpt].getDureeRevision();

    }
    return total;
}


/**
 * @brief Visite::getEtat
 * @return etat
 * retourne l'état de la visite
 */

char Visite::getEtat()
{
    return etat;
}

/**
 * @brief Visite::changerEtat
 * modifie l'état de la visite, de 'p' programmée à 'a' affectée, ou de 'a' affectée à 'r' réalisée
 */

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

/**
 * @brief Visite::addBorne
 * @param laBorne
 * permet l'ajout d'une borne
 */

void Visite::addBorne(Borne laBorne)
{
   tabBorne.push_back(laBorne);
}



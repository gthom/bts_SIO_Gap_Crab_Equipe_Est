#include <iostream>
#include "typeBorne.h"

//constructeur
TypeBorne::TypeBorne(string c, int d, int n, int a)
{
    codeTypeBorne=c;
    dureeRevision=d;
    nbJoursEntreRevisions=n;
    nbUnitesEntreRevisions=a;
}

TypeBorne::TypeBorne()
{
    //constructeur vide
}

//Implémentation
int TypeBorne::getDureeRevision()
{
    return dureeRevision;
}

int TypeBorne::getNbJoursEntreRevisions()
{
    return nbJoursEntreRevisions;
}

int TypeBorne::getNbUnitesEntreRevisions()
{
    return nbUnitesEntreRevisions;
}

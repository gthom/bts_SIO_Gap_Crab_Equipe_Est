#include "borne.h"
#include "typeborne.h"

void Borne::getDureeRevision()
{
	return dureeRevision;
}

void Borne::estAReviser()
{
    //if(QDate::nbJoursEntreRevisions > ((QDate::currentDate())-(QDate::dateDerniereRevision)))
//	{
//		return true;
//	}
//	else
//	{
        if(indiceCompteurUnites > nbUnitesEntreRevisions)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

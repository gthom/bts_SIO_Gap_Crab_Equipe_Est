#include "borne.h"
#include "typeborne.h"

void Borne::getDureeRevision()
{
	return dureeRevision;
}

void Borne::estAReviser()
{
    	// On crée une variable qui reçoit la date du jour
	 QDate dateDuJour = QDate::currentDate();
    	// On récupère la date de la dernière révision dans la BDD
    	QDate dateDerniereRevision = QDate(2015,9,5);
    	// On calcule la différence entre 2 dates
    	int maDate = dateDerniereRevision.daysTo(dateDuJour);
    	
    	if(nbJoursEntreRevisions > maDate)
	{
		return true;
	}
	else
	{
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

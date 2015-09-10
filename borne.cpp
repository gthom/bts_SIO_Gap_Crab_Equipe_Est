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
	QSqlQueryModel model;
	model.setQuery("SELECT * FROM BORNE");
	int dateDerniereRevision = model.record(3).value("dateDerniereRevision").toInt();
	QDate dateDerRevision = QDate(dateDerniereRevision);
	
	// On calcule la différence entre 2 dates
	int maDate = dateDerRevision.daysTo(dateDuJour);
    	
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

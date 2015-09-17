#include "borne.h"
#include <QTableView>

int Borne::getDureeRevision()
{
    return dureeRevision;
}

bool Borne::estAReviser()
{        
    // On crée une variable qui reçoit la date du jour
    QDate dateDuJour = QDate::currentDate();
    // On récupère la date de la dernière révision dans la BDD
    QSqlQuery query("SELECT * FROM BORNE");
    int dateDerniereRevision = query.record(3).value("dateDerniereRevision").toInt();
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

#include "borne.h"
#include <QTableView>

Borne::Borne(int i, QDate ddr, int idcu)
{
    idBorne = i;
    dateDerniereRevision = ddr;
    indiceCompteurUnites = idcu;
}

Borne::Borne()
{

}

int Borne::getDureeRevision()
{
    int dureeRevision = 0;
    return dureeRevision;
}

bool Borne::estAReviser()
{        
    // On crée une variable qui reçoit la date du jour
    QDate dateDuJour = QDate::currentDate();
    // On récupère la date de la dernière révision dans la BDD
    QSqlQuery query("SELECT * FROM BORNE");
    int dateDerniereRevision = query.record().value("dateDerniereRevision").toInt();
    //QDate dateDerRevision = QDate(dateDerniereRevision);

    // On calcule la différence entre 2 dates
    int maDate = 0; //dateDerRevision.daysTo(dateDuJour);
    int nbJoursEntreRevisions = 0;
    int indiceCompteurUnites = 0;
    int nbUnitesEntreRevisions = 0;


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
    return 0;
}

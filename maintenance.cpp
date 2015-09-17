#include "maintenance.h"
#include <iostream>
#include <vector>

Maintenance::Maintenance(vector<Station> ls, vector<Technicien> lt, vector<Visite> lv)
{
    lesStations = ls;
    lesTechniciens = lt;
    lesVisites = lv;
}

Maintenance::Maintenance()
{
}

void Maintenance::reviser()
{

}

void Maintenance::affecterVisites()
{

}

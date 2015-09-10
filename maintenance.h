/**
 * @author Robin Lesieur
 * @file maintenance.h
 * @date 10/08/15
 * @class Maintenance
 */

#include technicien.h
#include station.h
#ifndef MAINTENANCE_H
#define MAINTENANCE_H

class Maintenance
{
public:
    Maintenance();

    void reviser ();
    void affecterVisites();
};

#endif // MAINTENANCE_H

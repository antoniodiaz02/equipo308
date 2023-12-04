#ifndef ACTIVIDADES_ACADEMICAS_H
#define ACTIVIDADES_ACADEMICAS_H

#include <iostream>
#include <string>

using namespace std;

class ActividadesAcademicas 
{

    private:

        int id_actividad;
        string nombre;
        string fecha;
        string tematica;
        int aforo;
        string ubicacion;
        float precio;
        string tipo;

    public:
    
        ActividadesAcademicas(int id_actividad_, string nombre_, string fecha_, string tematica_, int aforo_, string ubicacion_, float precio_, string tipo_);
        string MostrarActividad();
};

#endif

#ifndef ACTIVIDADES_ACADEMICAS_H
#define ACTIVIDADES_ACADEMICAS_H

#include <fstream>
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
	int id_director;

    public:

        ActividadesAcademicas(int id_actividad_, string nombre_, string fecha_, string tematica_, int aforo_, string ubicacion_, float precio_, string tipo_, int id_director_);
        string MostrarActividad();
        static void EliminarActividadPorID(int id);
        static void ModificarActividadPorID(int id);
        static void MostrarTodasActividades();
	    // static void modificarActividadPorID();

        int getIdActividad() const;
        std::string getNombre() const;
        std::string getFecha() const;
        std::string getTematica() const;
        int getAforo() const;
        std::string getUbicacion() const;
        float getPrecio() const;
        std::string getTipo() const;
        int getIdDirector() const;

        // Métodos Set
        void setIdActividad(int idactividad);
        void setNombre(std::string nombre);
        void setFecha(std::string fecha);
        void setTematica(std::string tematica);
        void setAforo(int aforo);
        void setUbicacion(std::string ubicacion);
        void setPrecio(float precio);
        void setTipo(std::string tipo_);
        void setIdDirector(int iddirector);
};

#endif

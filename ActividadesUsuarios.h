// actividadesusuarios.h
#ifndef ACTIVIDADESUSUARIOS_H
#define ACTIVIDADESUSUARIOS_H

#include <iostream>
#include <fstream>

class ActividadesUsuarios {
private:
    int idUsuario;
    int idActividad;

public:
    ActividadesUsuarios(int idUsuario, int idActividad);
    void setIdUsuario(int id);
    int getIdUsuario() const;
    void setIdActividad(int id);
    int getIdActividad() const;
    void guardarEnArchivo();
    static void mostrarArchivo();
    static void cancelarInscripcion(int idUsuario, int idActividad);
};

#endif // ACTIVIDADESUSUARIOS_H

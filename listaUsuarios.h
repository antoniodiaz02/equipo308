#include <iostream>
#include <vector>
#include <fstream>
#include "usuario.h"

class ListaUsuarios {
private:
    int aforo;
    std::vector<Usuario> listaUsuarios;
    int id_actividad;

public:
    // Constructor
    ListaUsuarios(int aforo, int id_actividad) : aforo(aforo), id_actividad(id_actividad) {}

    // Métodos de acceso (getters)
    int getAforo() const {
        return aforo;
    }

    int getIdActividad() const {
        return id_actividad;
    }

    const std::vector<Usuario>& getListaUsuarios() const {
        return listaUsuarios;
    }

    // Métodos de modificación (setters)
    void setAforo(int nuevoAforo) {
        aforo = nuevoAforo;
    }

    void setIdActividad(int nuevoIdActividad) {
        id_actividad = nuevoIdActividad;
    }

    // Método para añadir usuario a la lista
    void añadirUsuario(const Usuario& usuario) {
        listaUsuarios.push_back(usuario);
    }

    //Comprobar si un usuario ya esta añadido
    bool usuarioAñadido(const Usuario& usuario, const std::vector<Usuario>& listaUsuarios);

    //Ver si una actividad existe
    bool actividadExistente(int idActividad);

    //Añadirlo si se cumple
    
    void añadirUsuarioActividad(int id_usuario, int idActividad);

};

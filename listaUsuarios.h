#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Usuario {
private:
    int id_usuario;
    std::string nombre;

public:
    Usuario(int id, const std::string& n);

    int getIdUsuario() const;

    const std::string& getNombre() const;
};

class ListaUsuarios {
private:
    std::vector<Usuario> listaUsuarios;
    int id_actividad;

public:
    ListaUsuarios(int id);

    bool usuarioExistente(int idUsuario) const;

    bool actividadExistente(int idActividad) const;

    void añadirUsuario(const Usuario& usuario);

    void mostrarUsuarios() const;

    const std::string& getNombreActividad() const;
};

void añadirUsuarioActividad(int id_usuario, int id_actividad, const std::vector<ListaUsuarios>& listasUsuarios);

#endif

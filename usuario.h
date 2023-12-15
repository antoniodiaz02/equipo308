#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>

class Usuario {
private:
    std::string nombre;
    int id_usuario;
    std::string correo;

public:
    // Constructor
    Usuario(const std::string& nombre, int id_usuario, const std::string& correo)
        : nombre(nombre), id_usuario(id_usuario), correo(correo) {}

    // Métodos de acceso (getters)
    std::string getNombre() const {
        return nombre;
    }

    int getIdUsuario() const {
        return id_usuario;
    }

    std::string getCorreo() const {
        return correo;
    }

    // Métodos de modificación (setters)
    void setNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    void setIdUsuario(int nuevoIdUsuario) {
        id_usuario = nuevoIdUsuario;
    }

    void setCorreo(const std::string& nuevoCorreo) {
        correo = nuevoCorreo;
    }

    
};

#endif
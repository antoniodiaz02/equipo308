// DirectorAcademico.cc

#include "directorAcademico.h"

// Constructor vacío
DirectorAcademico::DirectorAcademico() : id_director(0), nombre_completo(""), contrasenia("") {}

// Constructor parametrizado
DirectorAcademico::DirectorAcademico(int id, const std::string& nombre, const std::string& contrasenia)
    : id_director(id), nombre_completo(nombre), contrasenia(contrasenia) {
    // Al crear un nuevo director, guardar la información en un fichero
    guardarEnFichero();
}

// Métodos getters
int DirectorAcademico::getIdDirector() const {
    return id_director;
}

std::string DirectorAcademico::getNombreCompleto() const {
    return nombre_completo;
}

std::string DirectorAcademico::getContrasenia() const {
    return contrasenia;
}

// Métodos setters
void DirectorAcademico::setIdDirector(int id) {
    id_director = id;
}

void DirectorAcademico::setNombreCompleto(const std::string& nombre) {
    nombre_completo = nombre;
}

void DirectorAcademico::setContrasenia(const std::string& contrasenia) {
    this->contrasenia = contrasenia;
}

// Método para guardar la información en un fichero
void DirectorAcademico::guardarEnFichero() const {
     std::ofstream archivo("directores_academicos.txt", std::ios::app);

        if (archivo.is_open()) {
            archivo << "ID: " << id_director << "\n";
            archivo << "Nombre completo: " << nombre_completo << "\n";
            archivo << "Contraseña: " << contrasenia << "\n\n";

            archivo.close();
            std::cout << "Información del director guardada en el fichero.\n";
        } else {
            std::cerr << "Error al abrir el fichero para guardar la información.\n";
        }
}

// DirectorAcademico.h

#ifndef DIRECTOR_ACADEMICO_H
#define DIRECTOR_ACADEMICO_H

#include <iostream>
#include <fstream>
#include <string>

class DirectorAcademico {
private:
    int id_director;
    std::string nombre_completo;
    std::string contrasenia;

public:
    // Constructor vacío
    DirectorAcademico();

    // Constructor parametrizado
    DirectorAcademico(int id, const std::string& nombre, const std::string& contrasenia);

    // Métodos getters
    int getIdDirector() const;
    std::string getNombreCompleto() const;
    std::string getContrasenia() const;

    // Métodos setters
    void setIdDirector(int id);
    void setNombreCompleto(const std::string& nombre);
    void setContrasenia(const std::string& contrasenia);

    void guardarEnFichero() const;
};

#endif 

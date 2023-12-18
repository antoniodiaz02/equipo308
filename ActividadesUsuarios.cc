// actividadesusuarios.cc
#include "ActividadesUsuarios.h"

ActividadesUsuarios::ActividadesUsuarios(int idUsuario, int idActividad) : idUsuario(idUsuario), idActividad(idActividad) {}

void ActividadesUsuarios::setIdUsuario(int id) {
    idUsuario = id;
}

int ActividadesUsuarios::getIdUsuario() const {
    return idUsuario;
}

void ActividadesUsuarios::setIdActividad(int id) {
    idActividad = id;
}

int ActividadesUsuarios::getIdActividad() const {
    return idActividad;
}

void ActividadesUsuarios::guardarEnArchivo() {
    std::ofstream archivo("usuariosinscritos.txt", std::ios::app);
    if (archivo.is_open()) {
        archivo << "ID Usuario: " << idUsuario << ", ID Actividad: " << idActividad << std::endl;
        archivo.close();
        std::cout << "Información guardada en usuariosinscritos.txt" << std::endl;
    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }
}

void ActividadesUsuarios::mostrarArchivo() {
    cout << "Depurando"<<endl;
    std::ifstream archivo("usuariosinscritos.txt");
    if (archivo.is_open()) {
        std::string linea;
        std::cout << "Contenido de usuariosinscritos.txt:" << std::endl;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo 'usuariosinscritos.txt'." << std::endl;
        // Imprimir información adicional sobre el error
        perror("Error");
    }
}

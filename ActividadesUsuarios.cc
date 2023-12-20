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

void ActividadesUsuarios::cancelarInscripcion(int idUsuario, int idActividad) {
    std::ifstream archivoEntrada("usuariosinscritos.txt");
    std::ofstream archivoTemp("temp.txt");

    std::string linea;
    bool inscripcionEncontrada = false;

    while (std::getline(archivoEntrada, linea)) {
        size_t posIdUsuario = linea.find("ID Usuario: ");
        if (posIdUsuario != std::string::npos) {
            int idUsuarioEncontrado = std::stoi(linea.substr(posIdUsuario + 12));

            // Obtener el id de la actividad desde la línea
            size_t posIdActividad = linea.find("ID Actividad: ");
            if (posIdActividad != std::string::npos) {
                int idActividadEncontrado = std::stoi(linea.substr(posIdActividad + 14));

                // Verificar tanto el ID de usuario como el ID de actividad
                if (idUsuarioEncontrado == idUsuario && idActividadEncontrado == idActividad) {
                    inscripcionEncontrada = true;
                    continue;  // No copiar la línea actual al archivo temporal
                }
            }
        }
        archivoTemp << linea << '\n';
    }

    archivoEntrada.close();
    archivoTemp.close();

    // Renombrar el archivo temporal al archivo original
    if (inscripcionEncontrada) {
        if (std::remove("usuariosinscritos.txt") != 0) {
            std::cerr << "Error al borrar el archivo original.\n";
            return;
        }
        if (std::rename("temp.txt", "usuariosinscritos.txt") != 0) {
            std::cerr << "Error al renombrar el archivo temporal.\n";
        }
        std::cout<< "\n";
        std::cout << "Inscripción cancelada correctamente.\n";
    } else {
        std::remove("temp.txt");  // No se encontró la inscripción, eliminar el archivo temporal
        std::cout << "No se encontró ninguna inscripción con el ID de usuario y actividad proporcionados.\n";
    }
}


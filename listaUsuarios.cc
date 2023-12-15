#include "listaUsuarios.h"
#include "usuario.h"

    


  //Comprobar si un usuario esta dentro de la lista
    bool usuarioExistente(const Usuario& usuario, const std::vector<Usuario>& listaUsuarios) {
    for (const Usuario& usuarioExistente : listaUsuarios) {
        if (usuarioExistente.getIdUsuario() == usuario.getIdUsuario()) {
            return true;
        }
    }
    return false;
    }
    //Comprobar si existe una actividad mediante su ID
    bool actividadExistente(int idActividad) {
    std::ifstream archivoEntrada("usuario_actividades.txt");

    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo 'actividades.txt' para leer.\n";
        return false;
    }

    std::string linea;
    while (std::getline(archivoEntrada, linea)) {
        // Supongamos que cada actividad en el archivo tiene el formato "ID: <id>"
        size_t pos = linea.find("ID: ");
        if (pos != std::string::npos) {
            int idEncontrado = std::stoi(linea.substr(pos + 4));
            if (idEncontrado == idActividad) {
                archivoEntrada.close();
                return true;
            }
        }
    }

    archivoEntrada.close();
    return false;
}

//Añadir a la actividad
void añadirUsuarioActividad(const Usuario& usuario, int idActividad, ListaUsuarios& listaUsuarios) {
    if (listaUsuarios.usuarioExistente(usuario.getIdUsuario()) && listaUsuarios.actividadExistente(idActividad)) {
        std::ofstream archivoSalida("usuarios_actividades.txt", std::ios::app);

        if (archivoSalida.is_open()) {
            archivoSalida << "ID_Usuario: " << usuario.getIdUsuario() << "\tID_Actividad: " << idActividad << "\n";
            std::cout << "Usuario añadido a la actividad correctamente.\n";
            archivoSalida.close();
        } else {
            std::cerr << "Error al abrir el archivo 'usuarios_actividades.txt' para escribir.\n";
        }
    } else {
        std::cout << "Usuario o actividad no existente en la lista.\n";
    }
}
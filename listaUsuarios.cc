#include "listaUsuarios.h"

// Implementaciones de las funciones...

// Constructor de Usuario
Usuario::Usuario(int id, const std::string& n) : id_usuario(id), nombre(n) {}

// Métodos de acceso de Usuario
int Usuario::getIdUsuario() const {
    return id_usuario;
}

const std::string& Usuario::getNombre() const {
    return nombre;
}

// Constructor de ListaUsuarios
ListaUsuarios::ListaUsuarios(int id) : id_actividad(id) {}

// Métodos de ListaUsuarios
bool ListaUsuarios::usuarioExistente(int idUsuario) const {
    for (const Usuario& usuario : listaUsuarios) {
        if (usuario.getIdUsuario() == idUsuario) {
            return true;
        }
    }
    return false;
}

bool ListaUsuarios::actividadExistente(int idActividad) const {
    return (idActividad == id_actividad);
}

void ListaUsuarios::añadirUsuario(const Usuario& usuario) {
    listaUsuarios.push_back(usuario);
}

void ListaUsuarios::mostrarUsuarios() const {
    std::cout << "Usuarios en la actividad " << id_actividad << ":\n";
    for (const Usuario& usuario : listaUsuarios) {
        std::cout << "ID: " << usuario.getIdUsuario() << "\tNombre: " << usuario.getNombre() << "\n";
    }
}

const std::string& ListaUsuarios::getNombreActividad() const {
    // Supongamos que tienes un método para obtener el nombre de la actividad
    // o que tienes el nombre almacenado en algún lugar
    // Por ejemplo, podrías agregar un miembro string nombreActividad a la clase
    // o un método que obtenga el nombre de una base de datos, etc.
    // En este caso, devolveré un nombre ficticio "ActividadX" como ejemplo.
    static const std::string nombreActividad = "ActividadX";
    return nombreActividad;
}

// Implementación de añadirUsuarioActividad
void añadirUsuarioActividad(int id_usuario, int id_actividad, const std::vector<ListaUsuarios>& listasUsuarios) {
    for (const ListaUsuarios& lista : listasUsuarios) {
        if (lista.actividadExistente(id_actividad)) {
            if (!lista.usuarioExistente(id_usuario)) {
                // El usuario no está añadido previamente
                std::ofstream archivoSalida("usuarios_actividades.txt", std::ios::app);
                if (archivoSalida.is_open()) {
                    archivoSalida << "ID_Usuario: " << id_usuario << "\tNombre_Actividad: " << lista.getNombreActividad() << "\n";
                    std::cout << "Usuario añadido a la actividad correctamente.\n";
                    archivoSalida.close();
                    return;  // Salir del bucle una vez que se ha añadido el usuario
                } else {
                    std::cerr << "Error al abrir el archivo 'usuarios_actividades.txt' para escribir.\n";
                }
            } else {
                std::cout << "El usuario ya está añadido a esta actividad.\n";
                return;
            }
        }
    }

    std::cout << "La actividad con ID " << id_actividad << " no existe en ninguna lista.\n";
}

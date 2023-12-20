#include "actividadesAcademicas.h"

ActividadesAcademicas::ActividadesAcademicas(int id_actividad_, string nombre_, string fecha_, string tematica_,
                                            int aforo_, string ubicacion_, float precio_, string tipo_,int id_director_) 
 {
    id_actividad = id_actividad_;
    nombre = nombre_;
    fecha = fecha_;
    tematica = tematica_;
    aforo = aforo_;
    ubicacion = ubicacion_;
    precio = precio_;
    tipo = tipo_;
    id_director = id_director_;
}

// Métodos Get
int ActividadesAcademicas::getIdActividad() const {
    return id_actividad;
}

std::string ActividadesAcademicas::getNombre() const {
    return nombre;
}

std::string ActividadesAcademicas::getFecha() const {
    return fecha;
}

std::string ActividadesAcademicas::getTematica() const {
    return tematica;
}

int ActividadesAcademicas::getAforo() const {
    return aforo;
}

std::string ActividadesAcademicas::getUbicacion() const {
    return ubicacion;
}

float ActividadesAcademicas::getPrecio() const {
    return precio;
}

std::string ActividadesAcademicas::getTipo() const {
    return tipo;
}

int ActividadesAcademicas::getIdDirector() const {
    return id_director;
}

// Métodos Set
void ActividadesAcademicas::setIdActividad(int idactividad) {
    id_actividad = idactividad;
}

void ActividadesAcademicas::setNombre(std::string nombre) {
    nombre = nombre;
}

void ActividadesAcademicas::setFecha(std::string fecha) {
    fecha = fecha;
}

void ActividadesAcademicas::setTematica(std::string tematica) {
    tematica = tematica;
}

void ActividadesAcademicas::setAforo(int aforo) {
    aforo = aforo;
}

void ActividadesAcademicas::setUbicacion(std::string ubicacion) {
    ubicacion = ubicacion;
}

void ActividadesAcademicas::setPrecio(float precio) {
    precio = precio;
}

void ActividadesAcademicas::setTipo(std::string tipo) {
    tipo = tipo;
}

void ActividadesAcademicas::setIdDirector(int iddirector) {
    id_director = iddirector;
}


string ActividadesAcademicas::MostrarActividad() 
{
    return "ID: " + to_string(id_actividad) + "\nNombre: " + nombre + "\nFecha: " + fecha + "\nTematica: " + tematica +
           "\nAforo: " + to_string(aforo) + "\nUbicacion: " + ubicacion +
           "\nPrecio: " + to_string(precio) + "\nTipo: " + tipo + "\nID_Director: " + to_string(id_director) + "\n\n";
}


ActividadesAcademicas crearActividad()
{
    int id;
    string nombre, fecha, tematica, ubicacion, tipo;
    int aforo, id_director;
    float precio;

    cout << "Ingrese el ID de la actividad: ";
    cin >> id;

    cout << "Ingrese el nombre de la actividad: ";
    cin.ignore();  
    getline(cin, nombre);

    cout << "Ingrese la fecha de la actividad: ";
    getline(cin, fecha);

    cout << "Ingrese la temática de la actividad: ";
    getline(cin, tematica);

    cout << "Ingrese el aforo de la actividad: ";
    cin >> aforo;

    cout << "Ingrese la ubicación de la actividad: ";
    cin.ignore();  
    getline(cin, ubicacion);

    cout << "Ingrese el precio de la actividad: ";
    cin >> precio;

    cout << "Ingrese el tipo de la actividad: ";
    cin.ignore();  
    getline(cin, tipo);

    cout << "Ingrese el ID del director asociado a la actividad: ";
    cin >> id_director;

    ActividadesAcademicas actividad(id, nombre, fecha, tematica, aforo, ubicacion, precio, tipo, id_director);

    ofstream archivo("actividad.txt", ios::app);

    if (archivo.is_open()) 
    {
        archivo << actividad.MostrarActividad() << " " << endl;
        cout << "\nActividad creada y agregada a 'actividad.txt'.\n";

        archivo.close();
    } 
    else 
    {
        cout << "Error al abrir el archivo para escribir.\n";
    }

    return actividad;
}


    void ActividadesAcademicas::EliminarActividadPorID(int id) {
        
    std::ifstream archivoEntrada("actividad.txt");
    std::ofstream archivoTemp("temp.txt");

    if (!archivoEntrada.is_open() || !archivoTemp.is_open()) {
        std::cerr << "Error al abrir los archivos.\n";
        return;
    }

    std::string linea;
    bool actividadEncontrada = false;

    while (std::getline(archivoEntrada, linea)) {
        size_t pos = linea.find("ID: ");
        if (pos != std::string::npos) {
            int idEncontrado = std::stoi(linea.substr(pos + 4));
            if (idEncontrado == id) {
                actividadEncontrada = true;
                // No copiar la línea actual al archivo temporal (ignorar toda la actividad)
                while (std::getline(archivoEntrada, linea) && !linea.empty()) {
                    continue;
                }
                continue;  // No copiar la línea actual al archivo temporal
            }
        }
        archivoTemp << linea << '\n';
    }

    archivoEntrada.close();
    archivoTemp.close();

    // Renombrar el archivo temporal al archivo original
    if (actividadEncontrada) {
        if (std::remove("actividad.txt") != 0) {
            std::cerr << "Error al borrar el archivo original.\n";
            return;
        }
        if (std::rename("temp.txt", "actividad.txt") != 0) {
            std::cerr << "Error al renombrar el archivo temporal.\n";
        }
        std::cout << "Actividad eliminada correctamente.\n";
    } else {
        std::remove("temp.txt");  // No se encontró la actividad, eliminar el archivo temporal
        std::cout << "No se encontró ninguna actividad con el ID proporcionado.\n";
    }
}


    void ActividadesAcademicas::MostrarTodasActividades() {
    ifstream archivoEntrada("actividad.txt");

    if (!archivoEntrada.is_open()) {
        cerr << "Error al abrir el archivo para leer.\n";
        return;
    }

    string linea;
    while (getline(archivoEntrada, linea)) {
        cout << linea << endl;
    }

    archivoEntrada.close();
    }



void ActividadesAcademicas::ModificarActividadPorID(int id) {

 std::ifstream archivoEntrada("actividad.txt");
    std::ofstream archivoTemp("temp.txt");

    if (!archivoEntrada.is_open() || !archivoTemp.is_open()) {
        std::cerr << "Error al abrir los archivos.\n";
        return;
    }

    std::string linea;
    bool actividadEncontrada = false;

    while (std::getline(archivoEntrada, linea)) {
        size_t pos = linea.find("ID: ");
        if (pos != std::string::npos) {
            int idEncontrado = std::stoi(linea.substr(pos + 4));
            if (idEncontrado == id) {
                actividadEncontrada = true;
                // No copiar la línea actual al archivo temporal (ignorar toda la actividad)
                while (std::getline(archivoEntrada, linea) && !linea.empty()) {
                    continue;
                }
                continue;  // No copiar la línea actual al archivo temporal
            }
        }
        archivoTemp << linea << '\n';
    }

    archivoEntrada.close();
    archivoTemp.close();

    // Renombrar el archivo temporal al archivo original
    if (actividadEncontrada) {
        if (std::remove("actividad.txt") != 0) {
            std::cerr << "Error al borrar el archivo original.\n";
            return;
        }
        if (std::rename("temp.txt", "actividad.txt") != 0) {
            std::cerr << "Error al renombrar el archivo temporal.\n";
        }
        std::cout << "Modificando actividad....\n";
    } else {
        std::remove("temp.txt");  // No se encontró la actividad, eliminar el archivo temporal
        std::cout << "No se encontró ninguna actividad con el ID proporcionado.\n";
    }
}

#include "actividadesAcademicas.h"
#include <fstream> 

ActividadesAcademicas::ActividadesAcademicas(int id_actividad_, string nombre_, string fecha_, string tematica_,
                                            int aforo_, string ubicacion_, float precio_, string tipo_) 
 {
    id_actividad = id_actividad_;
    nombre = nombre_;
    fecha = fecha_;
    tematica = tematica_;
    aforo = aforo_;
    ubicacion = ubicacion_;
    precio = precio_;
    tipo = tipo_;
}

string ActividadesAcademicas::MostrarActividad() 
{
    return "ID: " + to_string(id_actividad) + "\nNombre: " + nombre + "\nFecha: " + fecha + "\nTematica: " + tematica +
           "\nAforo: " + to_string(aforo) + "\nUbicacion: " + ubicacion +
           "\nPrecio: " + to_string(precio) + "\nTipo: " + tipo + "\n\n";
}


ActividadesAcademicas CrearActividad()
{

    int id;
    string nombre, fecha, tematica, ubicacion, tipo;
    int aforo;
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

    ActividadesAcademicas actividad(id, nombre, fecha, tematica, aforo, ubicacion, precio, tipo);

    ofstream archivo("actividad.txt", ios::app);

    if (archivo.is_open()) 
    {
        
        archivo << actividad.MostrarActividad();
        cout << "\nActividad creada y agregada a 'actividad.txt'.\n";

        archivo.close();
    } 
    else 
    {
        cout << "Error al abrir el archivo para escribir.\n";
    }
}


    void ActividadesAcademicas::EliminarActividadPorID(int id) 
    {

    std::ifstream archivoEntrada("actividad.txt");
    std::ofstream archivoTemp("temp.txt");

    if (!archivoEntrada.is_open() || !archivoTemp.is_open()) {
        std::cerr << "Error al abrir los archivos.\n";
        return;
    }

    std::string linea;
    bool actividadEncontrada = false;

    while (std::getline(archivoEntrada, linea)) {
        // Supongamos que cada actividad en el archivo tiene el formato "ID: <id>"
        size_t pos = linea.find("ID: ");
        if (pos != std::string::npos) {
            int idEncontrado = std::stoi(linea.substr(pos + 4));
            if (idEncontrado == id) {
                actividadEncontrada = true;
                continue;  // No copiar la línea actual al archivo temporal
            }
        }
        archivoTemp << linea << '\n';
    }

    archivoEntrada.close();
    archivoTemp.close();

    // Renombrar el archivo temporal al archivo original
    if(actividadEncontrada) {
        if (std::remove("actividad.txt") != 0) {
            std::cerr << "Error al borrar el archivo original.\n";
            return;
        }
        if (std::rename("temp.txt", "actividad.txt") != 0) {
            std::cerr << "Error al renombrar el archivo temporal.\n";
        }
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
    ifstream archivoEntrada("actividad.txt");
    ofstream archivoTemp("temp.txt", ios::app);

    if (!archivoEntrada.is_open() || !archivoTemp.is_open()) {
        cerr << "Error al abrir los archivos.\n";
        return;
    }

    string linea;
    bool actividadEncontrada = false;

    while (getline(archivoEntrada, linea)) {
        size_t pos = linea.find("ID: ");
        if (pos != string::npos) {
            int idEncontrado = stoi(linea.substr(pos + 4));
            if (idEncontrado == id) {
                actividadEncontrada = true;

                // Mostrar la actividad actual
                cout << "Actividad Actual:\n" << linea << endl;

                // Pedir al usuario que modifique cada campo
                cout << "¿Desea modificar el nombre? (S/N): ";
                char respuesta;
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese el nuevo nombre de la actividad: ";
                    string nuevoNombre;
                    cin.ignore();
                    getline(cin, nuevoNombre);

                    // Actualizar la línea con el nuevo nombre
                    size_t posNombre = linea.find("Nombre: ");
                    if (posNombre != string::npos) {
                        linea.replace(posNombre + 8, linea.find("\n", posNombre) - (posNombre + 8), nuevoNombre);
                    }
                }

                // Repetir el proceso para otros campos
                cout << "¿Desea modificar la fecha? (S/N): ";
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese la nueva fecha de la actividad: ";
                    string nuevaFecha;
                    cin.ignore();
                    getline(cin, nuevaFecha);
                    size_t posFecha = linea.find("Fecha: ");
                    if (posFecha != string::npos) {
                        linea.replace(posFecha + 7, linea.find("\n", posFecha) - (posFecha + 7), nuevaFecha);
                    }
                }

                // Repetir para otros campos...
                cout << "¿Desea modificar la tematica? (S/N): ";
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese la nueva tematica de la actividad: ";
                    string nuevaTematica;
                    cin.ignore();
                    getline(cin, nuevaTematica);
                    size_t posTematica = linea.find("Tematica: ");
                    if (posTematica != string::npos) {
                        linea.replace(posTematica + 10, linea.find("\n", posTematica) - (posTematica + 10), nuevaTematica);
                    }
                }

                cout << "¿Desea modificar el aforo? (S/N): ";
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese el nuevo aforo de la actividad: ";
                    int nuevoAforo;
                    cin >> nuevoAforo;
                    size_t posAforo = linea.find("Aforo: ");
                    if (posAforo != string::npos) {
                        linea.replace(posAforo + 7, linea.find("\n", posAforo) - (posAforo + 7), to_string(nuevoAforo));
                    }
                }

                cout << "¿Desea modificar la ubicacion? (S/N): ";
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese la nueva ubicacion de la actividad: ";
                    string nuevaUbicacion;
                    cin.ignore();
                    getline(cin, nuevaUbicacion);
                    size_t posUbicacion = linea.find("Ubicacion: ");
                    if (posUbicacion != string::npos) {
                        linea.replace(posUbicacion + 11, linea.find("\n", posUbicacion) - (posUbicacion + 11), nuevaUbicacion);
                    }
                }

                cout << "¿Desea modificar el precio? (S/N): ";
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese el nuevo precio de la actividad: ";
                    float nuevoPrecio;
                    cin >> nuevoPrecio;
                    size_t posPrecio = linea.find("Precio: ");
                    if (posPrecio != string::npos) {
                        linea.replace(posPrecio + 8, linea.find("\n", posPrecio) - (posPrecio + 8), to_string(nuevoPrecio));
                    }
                }

                cout << "¿Desea modificar el tipo? (S/N): ";
                cin >> respuesta;

                if (toupper(respuesta) == 'S') {
                    cout << "Ingrese el nuevo tipo de la actividad: ";
                    string nuevoTipo;
                    cin.ignore();
                    getline(cin, nuevoTipo);
                    size_t posTipo = linea.find("Tipo: ");
                    if (posTipo != string::npos) {
                        linea.replace(posTipo + 6, linea.find("\n", posTipo) - (posTipo + 6), nuevoTipo);
                    }
                }

                cout << "Actividad Modificada:\n" << linea << endl;
            }
        }
        archivoTemp << linea << '\n';
    }

    archivoEntrada.close();
    archivoTemp.close();

    // Renombrar el archivo temporal al archivo original
    if (actividadEncontrada) {
        if (remove("actividad.txt") != 0) {
            cerr << "Error al borrar el archivo original.\n";
            return;
        }
        if (rename("temp.txt", "actividad.txt") != 0) {
            cerr << "Error al renombrar el archivo temporal.\n";
        }
    } else {
        remove("temp.txt");  // No se encontró la actividad, eliminar el archivo temporal
        cout << "No se encontró ninguna actividad con el ID proporcionado.\n";
    }
}
    

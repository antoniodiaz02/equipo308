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


string ActividadesAcademicas::MostrarActividad() 
{
    return "ID: " + to_string(id_actividad) + "\nNombre: " + nombre + "\nFecha: " + fecha + "\nTematica: " + tematica +
           "\nAforo: " + to_string(aforo) + "\nUbicacion: " + ubicacion +
           "\nPrecio: " + to_string(precio) + "\nTipo: " + tipo + "\nID_Director: " + to_string(id_director) + "\n\n";
}


ActividadesAcademicas CrearActividad()
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




void ActividadesAcademicas::modificarActividadPorID() {
    int id;
    std::cout << "Ingrese el ID de la actividad que desea modificar: ";
    std::cin >> id;

    // Abrir el archivo para lectura y escritura
    std::ifstream inFile("actividades.txt");
    std::ofstream outFile("temp.txt");

    bool actividadEncontrada = false;

    while (inFile >> ID >> Nombre >> Fecha >> Tematica >> Aforo >> Ubicacion >> Precio >> Tipo >> ID_Director) {
        // Verificar si esta es la actividad que queremos modificar
        if (ID == id) {
            actividadEncontrada = true;
            std::cout << "Ingrese los nuevos valores para la actividad:" << std::endl;
            std::cout << "Nombre: ";
            std::cin >> Nombre;
            std::cout << "Fecha: ";
            std::cin >> Fecha;
            std::cout << "Tematica: ";
            std::cin >> Tematica;
            std::cout << "Aforo: ";
            std::cin >> Aforo;
            std::cout << "Ubicacion: ";
            std::cin >> Ubicacion;
            std::cout << "Precio: ";
            std::cin >> Precio;
            std::cout << "Tipo: ";
            std::cin >> Tipo;
            std::cout << "ID_Director: ";
            std::cin >> ID_Director;
        }

        // Escribir la actividad (modificada o no) en el nuevo archivo
        outFile << ID << " " << Nombre << " " << Fecha << " " << Tematica << " " << Aforo << " " << Ubicacion << " " << Precio << " " << Tipo
                << " " << ID_Director << std::endl;
    }

    // Cerrar los archivos
    inFile.close();
    outFile.close();

    // Renombrar el nuevo archivo como el archivo original
    remove("actividades.txt");
    rename("temp.txt", "actividades.txt");

    if (!actividadEncontrada) {
        std::cout << "No se encontró ninguna actividad con el ID proporcionado." << std::endl;
    } else {
        std::cout << "Actividad modificada exitosamente." << std::endl;
    }
}

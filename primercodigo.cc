#include "primercodigo.h"
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


ActividadesAcademicas CrearActividad(){

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
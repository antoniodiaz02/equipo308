#include "actividadesAcademicas.h"
#include "actividadesAcademicas.cc"
#include <iostream>

using namespace std;

const string CONTRASENA_ORGANIZADOR = "123";
const string CONTRASENA_DIRECTOR = "123";


void menuOrganizador() {
    string contrasena;
    // Solicitar la contraseña al organizador
    cout << "Ingrese la contraseña de organizador: ";
    cin >> contrasena;

    if (contrasena != CONTRASENA_ORGANIZADOR) {
        cout << "Error de autenticación. Programa finalizado." << endl;
        return;
    }

    int opcionOrganizador;

    cout << "Menú Organizador:" << endl;
    cout << "1. Crear actividad académica" << endl;
    cout << "2. Eliminar actividad académica" << endl;
    cout << "3. Modificar actividad académica" << endl;
    cout << "4. Cambiar rol a alguien" << endl;
    cout << "5. Crear mailing" << endl;
    cout << "6. Borrar mailing" << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
    cin >> opcionOrganizador;

    // Agrega el código para manejar las opciones del menú del organizador
    switch (opcionOrganizador) {
        case 1:
            cout << "Seleccionaste: Crear actividad académica" << endl;
            // Agrega el código para crear actividad académica
            CrearActividad();

            break;

        case 2:
            cout << "Seleccionaste: Eliminar actividad académica" << endl;
            // Agrega el código para eliminar actividad académica
            int idEliminar;
            cout << "Ingrese el ID de la actividad a eliminar: ";
            cin >> idEliminar;
            ActividadesAcademicas::EliminarActividadPorID(idEliminar);
            break;

        // ... Agrega más casos según tus necesidades ...

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
    }
}

void menuDirectorAcademico() {

    string contrasena;
    // Solicitar la contraseña al director académico
    cout << "Ingrese la contraseña de director académico: ";
    cin >> contrasena;

    if (contrasena != CONTRASENA_DIRECTOR) {
        cout << "Error de autenticación. Programa finalizado." << endl;
        return;
    }

    int opcionDirector;

    cout << "Menú Director Académico:" << endl;
    cout << "1. Enviar mailing" << endl;
    cout << "2. Ver actividades académicas disponibles" << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
    cin >> opcionDirector;

    // Agrega el código para manejar las opciones del menú del director académico
    switch (opcionDirector) {
        case 1:
            cout << "Seleccionaste: Enviar mailing" << endl;
            // Agrega el código para enviar mailing
            break;

        case 2:
            cout << "Seleccionaste: Ver actividades académicas disponibles" << endl;
            // Agrega el código para ver actividades académicas disponibles
            ActividadesAcademicas::MostrarTodasActividades();
            break;

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
    }
}

void menuUsuario() {
    int opcionUsuario;

    cout << "Menú Usuario:" << endl;
    cout << "1. Inscribirse en una actividad" << endl;
    cout << "2. Cancelar inscripción" << endl;
    cout << "3. Ver actividades disponibles" << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
    cin >> opcionUsuario;

    // Agrega el código para manejar las opciones del menú del usuario
    switch (opcionUsuario) {
        case 1:
            cout << "Seleccionaste: Inscribirse en una actividad" << endl;
            // Agrega el código para inscribirse en una actividad
            break;

        case 2:
            cout << "Seleccionaste: Cancelar inscripción" << endl;
            // Agrega el código para cancelar inscripción
            break;

        case 3:
            cout << "Seleccionaste: Ver actividades disponibles" << endl;
            // Agrega el código para ver actividades disponibles
            ActividadesAcademicas::MostrarTodasActividades();
            break;

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
    }
}

int main() {
    int opcion;

    cout << "Seleccione su rol:" << endl;
    cout << "1. Organizador" << endl;
    cout << "2. Director Academico" << endl;
    cout << "3. Usuario" << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "¡Bienvenido, Organizador!" << endl;
            menuOrganizador();
            break;

        case 2:
            cout << "¡Hola, Director Academico!" << endl;
            menuDirectorAcademico();
            break;

        case 3:
            cout << "¡Hola, Usuario!" << endl;
            menuUsuario();
            break;

        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
            break;
    }

    return 0;
}


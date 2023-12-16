#include "actividadesAcademicas.h"
#include "actividadesAcademicas.cc"
#include <iostream>

using namespace std;

const string CONTRASENA_ORGANIZADOR = "123";
const string CONTRASENA_DIRECTOR = "123";


void menuOrganizador() {
    string contrasena;

    do{
    // Solicitar la contraseña al organizador
    cout << "Ingrese la contraseña de organizador: ";
    cin >> contrasena;

    if (contrasena != CONTRASENA_ORGANIZADOR) {
        cout << "Error de autenticación. Programa finalizado." << endl;
        return;
    }
    }while (contrasena != CONTRASENA_ORGANIZADOR);

   int opcionOrganizador;
   
   do {
        cout << "Menú Organizador:" << endl;
        cout << "1. Crear actividad académica" << endl;
        cout << "2. Eliminar actividad académica" << endl;
        cout << "3. Modificar actividad académica" << endl;
        cout << "4. Cambiar rol a alguien" << endl;
        cout << "5. Crear mailing" << endl;
        cout << "6. Borrar mailing" << endl;
        cout << "7. Salir al menú principal" << endl;
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

            case 3:
                cout << "Seleccionaste: Modificar actividad académica" << endl;
                // Agrega el código para modificar actividad académica
                int idModificar;
                cout << "Ingrese el ID de la actividad a modificar: ";
                cin >> idModificar;
                ActividadesAcademicas::ModificarActividadPorID(idModificar);
                break;

            case 4:
                cout << "Seleccionaste: Cambiar rol a alguien" << endl;
                // Agrega el código para cambiar el rol de alguien
                // ...

                break;

            case 5:
                cout << "Seleccionaste: Crear mailing" << endl;
                // Agrega el código para crear mailing
                // ...

                break;

            case 6:
                cout << "Seleccionaste: Borrar mailing" << endl;
                // Agrega el código para borrar mailing
                // ...

                break;

            case 7:
                cout << "Volviendo al menú principal." << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcionOrganizador != 7);

}

void menuDirectorAcademico() {
    string contrasena;
    
    // Bucle do-while para mantenerse en el menú del director académico
    do {
        // Solicitar la contraseña al director académico
        cout << "Ingrese la contraseña de director académico: ";
        cin >> contrasena;

        if (contrasena != CONTRASENA_DIRECTOR) {
            cout << "Error de autenticación. Por favor, ingrese la contraseña nuevamente." << endl;
        }
    } while (contrasena != CONTRASENA_DIRECTOR);

    int opcionDirector;

    // Bucle do-while para mantenerse en el menú del director académico
    do {
        cout << "Menú Director Académico:" << endl;
        cout << "1. Enviar mailing" << endl;
        cout << "2. Ver actividades académicas disponibles" << endl;
        cout << "3. Salir al menú principal" << endl;
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

            case 3:
                cout << "Volviendo al menú principal." << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcionDirector != 3);
}


void menuUsuario() {
    int opcionUsuario;

    do {
        cout << "Menú Usuario:" << endl;
        cout << "1. Inscribirse en una actividad" << endl;
        cout << "2. Cancelar inscripción" << endl;
        cout << "3. Ver actividades disponibles" << endl;
        cout << "4. Salir al menú principal" << endl;
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

            case 4:
                cout << "Volviendo al menú principal" << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }

    } while (opcionUsuario != 4);
}

int main() {
    int opcion;

    do {
        cout << "Seleccione su rol:" << endl;
        cout << "1. Organizador" << endl;
        cout << "2. Director Academico" << endl;
        cout << "3. Usuario" << endl;
        cout << "4. Salir" << endl;
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

            case 4:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}


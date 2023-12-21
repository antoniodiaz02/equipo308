#include "actividadesAcademicas.h"
#include "actividadesAcademicas.cc"
#include "ActividadesUsuarios.h"
#include "ActividadesUsuarios.cc"
#include "MailingList.cc"
#include "MailingList.h"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

using namespace std;

// Definición de colores para la consola
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

const string CONTRASENA_ORGANIZADOR = "123";
const string CONTRASENA_DIRECTOR = "123";

void imprimirBienvenida(const string& rol) {
    cout << GREEN << "¡Bienvenido, " << rol << "!" << RESET << endl;
}

void imprimirDespedida() {
    cout << YELLOW << "Saliendo del programa. ¡Hasta luego!" << RESET << endl;
}

void imprimirErrorAutenticacion() {
    cout << RED << "Error de autenticación. Programa finalizado." << RESET << endl;
}

void imprimirOpcionInvalida() {
    cout << RED << "Opción no válida. Por favor, seleccione una opción válida." << RESET << endl;
}

void imprimirMenuOrganizador() {
    cout << "\n";
    cout << "Menú Organizador:" << endl;
    cout << "1. " << GREEN << "Eliminar actividad académica" << RESET << endl;
    cout << "2. " << GREEN << "Cambiar rol a alguien" << RESET << endl;
    cout << "3. " << YELLOW << "Salir al menú principal" << RESET << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
}

void imprimirMenuDirectorAcademico() {
    cout << "\n";
    cout << "Menú Director Académico:" << endl;
    cout << "1. " << GREEN << "Enviar mailing" << RESET << endl;
    cout << "2. " << GREEN << "Ver actividades académicas disponibles" << RESET << endl;
    cout << "3. " << GREEN << "Crear actividad académica" << RESET << endl;
    cout << "4. " << GREEN << "Modificar actividad académica" << RESET << endl;
    cout << "5. " << GREEN << "Ver lista usuarios inscritos en actividades" << RESET << endl;
    cout << "6. " << YELLOW << "Salir al menú principal" << RESET << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
}

void imprimirMenuUsuario() {
    cout << "\n";
    cout << "Menú Usuario:" << endl;
    cout << "1. " << GREEN << "Inscribirse en una actividad" << RESET << endl;
    cout << "2. " << GREEN << "Cancelar inscripción" << RESET << endl;
    cout << "3. " << GREEN << "Ver actividades disponibles" << RESET << endl;
    cout << "4. " << GREEN << "Mostrar actividades con usuarios inscritos" << RESET << endl;
    cout << "5. " << YELLOW << "Salir al menú principal" << RESET << endl;
    cout << "Ingrese el número correspondiente a su elección: ";
}

void menuOrganizador() {
    string contrasena;

    do {
        // Solicitar la contraseña al organizador
        cout << "Ingrese la contraseña de organizador: ";
        cin >> contrasena;

        if (contrasena != CONTRASENA_ORGANIZADOR) {
            imprimirErrorAutenticacion();
            return;
        }
    } while (contrasena != CONTRASENA_ORGANIZADOR);

    int opcionOrganizador;

    do {
        imprimirMenuOrganizador();
        cin >> opcionOrganizador;
        MailingList listaCorreos;

        // Agrega el código para manejar las opciones del menú del organizador
        switch (opcionOrganizador) {
            case 1:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Eliminar actividad académica" << RESET << endl;
                // Agrega el código para eliminar actividad académica
                int idEliminar;
                cout << "Ingrese el ID de la actividad a eliminar: ";
                cin >> idEliminar;
                ActividadesAcademicas::EliminarActividadPorID(idEliminar);
                break;

            case 2:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Cambiar rol a un usuario" << RESET << endl;
                cout << "Esta funcionalidad será desarrollada en la versión 2.0 de la aplicación" << endl;
                break;

            case 3:
                cout << "\n";
                cout << YELLOW << "Volviendo al menú principal." << RESET << endl;
                break;

            default:
                imprimirOpcionInvalida();
                break;
        }
    } while (opcionOrganizador != 3);
}

void menuDirectorAcademico() {
    string contrasena;

    do {
        // Solicitar la contraseña al director académico
        cout << "Ingrese la contraseña de director académico: ";
        cin >> contrasena;

        if (contrasena != CONTRASENA_DIRECTOR) {
            cout << "Error de autenticación. Por favor, ingrese la contraseña nuevamente." << endl;
        }
    } while (contrasena != CONTRASENA_DIRECTOR);

    int opcionDirector;

    do {
        imprimirMenuDirectorAcademico();
        cin >> opcionDirector;
        string mailing;
        string comando;

        // Agrega el código para manejar las opciones del menú del director académico
        switch (opcionDirector) {
            case 1:
                int opcion;

                cout << "Selecciona a quién enviar el código:" << endl;
                cout << "1. Estudiantes de la Politécnica" << endl;
                cout << "2. Alumnos de Veterinaria" << endl;
                cout << "3. A todos" << endl;

                cin >> opcion;

                if (opcion == 1) {
                    mailing = "politecnicamailing.txt";
                } else if (opcion == 2) {
                    mailing = "veterinariamailing.txt";
                } else if (opcion == 3) {
                    mailing = "todosmailing.txt";
                } else {
                    cerr << RED << "Opción no válida." << RESET << endl;
                }

                // Construye el comando para ejecutar el script de Python con la dirección de correo electrónico como argumento
                comando = "python3 enviarmailing.py " + mailing;

                // Ejecuta el comando
                system(comando.c_str());
                break;

            case 2:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Ver actividades académicas disponibles" << RESET << endl;
                // Agrega el código para ver actividades académicas disponibles
                ActividadesAcademicas::MostrarTodasActividades();
                break;

            case 3:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Crear actividad académica" << RESET << endl;
                // Agrega el código para ver actividades académicas disponibles
                crearActividad();
                break;

            case 4:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Modificar actividad académica" << RESET << endl;
                int id;
                cout << "Diga el id de la actividad que desea modificar: ";
                cin >> id;
                ActividadesAcademicas::ModificarActividadPorID(id);
                break;

            case 5:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Ver lista usuarios inscritos" << RESET << endl;
                ActividadesUsuarios::mostrarArchivo();
                break;

            case 6:
                cout << "\n";
                cout << YELLOW << "Volviendo al menú principal." << RESET << endl;
                break;

            default:
                imprimirOpcionInvalida();
                break;
        }
    } while (opcionDirector != 6);
}

void menuUsuario() {
    int opcionUsuario;

    do {
        imprimirMenuUsuario();
        cin >> opcionUsuario;
        ActividadesUsuarios ActividadUser(0, 0);

        // Agrega el código para manejar las opciones del menú del usuario
        switch (opcionUsuario) {
            case 1:
                // Opción 2: Inscribirse en una actividad
                cout << GREEN << "Seleccionaste: Inscribirse en una actividad" << RESET << endl;

                // Agrega el código para inscribirse en una actividad
                int idUsuario, idActividad;

                // Solicitar al usuario que ingrese los IDs
                cout << "Ingrese el ID del usuario: ";
                cin >> idUsuario;

                cout << "Ingrese el ID de la actividad: ";
                cin >> idActividad;

                // Crear una instancia de ActividadesUsuarios y guardar en archivo
                ActividadUser.setIdUsuario(idUsuario);
                ActividadUser.setIdActividad(idActividad);
                ActividadUser.guardarEnArchivo();
                cout << "Usuario inscrito en la actividad " << idActividad << endl;
                break;

            case 2:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Cancelar inscripción" << RESET << endl;
                // Agrega el código para cancelar inscripción
                int idUsuariocancelar;
                int idActividadecancelar;
                cout << "Ingrese el ID del usuario a eliminar: ";
                cin >> idUsuariocancelar;
                cout << "Ingrese el ID de la actividad a la que está inscrito: ";
                cin >> idActividadecancelar;
                ActividadesUsuarios::cancelarInscripcion(idUsuariocancelar, idActividadecancelar);
                break;

            case 3:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Ver actividades disponibles" << RESET << endl;
                // Agrega el código para ver actividades disponibles
                ActividadesAcademicas::MostrarTodasActividades();
                break;

            case 4:
                cout << "\n";
                cout << GREEN << "Seleccionaste: Ver lista usuarios inscritos" << RESET << endl;
                ActividadesUsuarios::mostrarArchivo();
                break;

            case 5:
                cout << "\n";
                cout << YELLOW << "Volviendo al menú principal." << RESET << endl;
                break;

            default:
                imprimirOpcionInvalida();
                break;
        }

    } while (opcionUsuario != 5);
}

int main() {
    int opcion;

    do {
        cout << "Seleccione su rol:" << endl;
        cout << "1. " << GREEN << "Organizador" << RESET << endl;
        cout << "2. " << GREEN << "Director Academico" << RESET << endl;
        cout << "3. " << GREEN << "Usuario" << RESET << endl;
        cout << "4. " << YELLOW << "Salir" << RESET << endl;
        cout << "Ingrese el número correspondiente a su elección: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                imprimirBienvenida("Organizador");
                menuOrganizador();
                break;

            case 2:
                imprimirBienvenida("Director Academico");
                menuDirectorAcademico();
                break;

            case 3:
                imprimirBienvenida("Usuario");
                menuUsuario();
                break;

            case 4:
                imprimirDespedida();
                break;

            default:
                imprimirOpcionInvalida();
                break;
        }

    } while (opcion != 4);

    return 0;
}


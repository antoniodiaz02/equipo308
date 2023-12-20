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
        cout<<"\n";
        cout << "Menú Organizador:" << endl;
        cout << "1. Eliminar actividad académica" << endl;
        cout << "2. Cambiar rol a alguien" << endl;
        cout << "3. Salir al menú principal" << endl;
        cout << "Ingrese el número correspondiente a su elección: ";
        cin >> opcionOrganizador;
	MailingList listaCorreos;

        // Agrega el código para manejar las opciones del menú del organizador
        switch (opcionOrganizador) {
            case 1:
                cout<<"\n";
                cout << "Seleccionaste: Eliminar actividad académica" << endl;
                // Agrega el código para eliminar actividad académica
                int idEliminar;
                cout << "Ingrese el ID de la actividad a eliminar: ";
                cin >> idEliminar;
                ActividadesAcademicas::EliminarActividadPorID(idEliminar);
                break;


            case 2:
                cout<<"\n";
                cout << "Seleccionaste: Cambiar rol a un usuario" << endl;
		cout << "Esta funcionalidad sera desarrollada en la version 2.0 de la aplicacion" << endl;
                break;

            case 3:
                cout<<"\n";
                cout << "Volviendo al menú principal." << endl;
                break;

            default:
                cout<<"\n";
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcionOrganizador != 3);

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
        cout<<"\n";
        cout << "Menú Director Académico:" << endl;
        cout << "1. Enviar mailing" << endl;
        cout << "2. Ver actividades académicas disponibles" << endl;
        cout << "3. Crear actividad académica" << endl;
	cout << "4. Modificar actividad académica" << endl;
	cout << "5. Ver lista usuarios incritos en actividades" << endl;
	cout << "6. Salir al menú principal" << endl;

        cout << "Ingrese el número correspondiente a su elección: ";
        cin >> opcionDirector;
	string mailing;
 	string comando;
        // Agrega el código para manejar las opciones del menú del director académico
        switch (opcionDirector) {
            case 1:
		 int opcion;

		std::cout << "Selecciona a quién enviar el código:" << std::endl;
    		std::cout << "1. Estudiantes de la Politécnica" << std::endl;
    		std::cout << "2. Alumnos de Veterinaria" << std::endl;
    		std::cout << "3. A todos" << std::endl;

    		std::cin >> opcion;


    		if (opcion == 1) {
        		mailing = "politecnicamailing.txt";
    		} else if (opcion == 2) {
        		mailing = "veterinariamailing.txt";
    		} else if (opcion == 3) {
        		mailing = "todosmailing.txt";
    		} else {
        		std::cerr << "Opción no válida." << std::endl;
    		}
    		// Construye el comando para ejecutar el script de Python con la dirección de correo electrónico como argumento
    		comando = "python3 enviarmailing.py " + mailing;

    		// Ejecuta el comando
    		system(comando.c_str());
                break;

            case 2:
                cout<<"\n";
                cout << "Seleccionaste: Ver actividades académicas disponibles" << endl;
                // Agrega el código para ver actividades académicas disponibles
                ActividadesAcademicas::MostrarTodasActividades();
                break;
	    
	    case 3:
                cout<<"\n";
                cout << "Seleccionaste: Crear actividad academica" << endl;
                // Agrega el código para ver actividades académicas disponibles
                CrearActividad();
                break;
            case 4:
                cout<<"\n";
                cout <<"Seleccionaster: Modificar actividad academica:" << endl;
		int id;
		cout<<"Diga el id de la actividad que desea modificar" << endl;
		cin>>id;
		ActividadesAcademicas::ModificarActividadPorID(id);
		
                break;
	    case 5:
                cout<<"\n";
                cout <<"Seleccionaste: Ver lista usuarios inscritos:" << endl;
                ActividadesUsuarios::mostrarArchivo();
                break;
            case 6:
		cout<<"\n";
                cout << "Volviendo al menú principal." << endl;
                break;


            default:
                cout<<"\n";
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcionDirector != 6);
}


void menuUsuario() {
    int opcionUsuario;

    do {
        cout<<"\n";
        cout << "Menú Usuario:" << endl;
        cout << "1. Inscribirse en una actividad" << endl;
        cout << "2. Cancelar inscripción" << endl;
        cout << "3. Ver actividades disponibles" << endl;
        cout << "4. Mostrar actividades con usuarios inscritos" << endl;
	cout << "5. Salir al menú principal" << endl;
        cout << "Ingrese el número correspondiente a su elección: ";
        cin >> opcionUsuario;
	ActividadesUsuarios ActividadUser(0, 0);
        // Agrega el código para manejar las opciones del menú del usuario
        switch (opcionUsuario) {
            case 1:
			 // Opción 2: Inscribirse en una actividad
            std::cout << "Seleccionaste: Inscribirse en una actividad" << std::endl;
            
            // Agrega el código para inscribirse en una actividad
            int idUsuario, idActividad;

            // Solicitar al usuario que ingrese los IDs
            std::cout << "Ingrese el ID del usuario: ";
            std::cin >> idUsuario;

            std::cout << "Ingrese el ID de la actividad: ";
            std::cin >> idActividad;
		
            // Crear una instancia de ActividadesUsuarios y guardar en archivo
            ActividadUser.setIdUsuario(idUsuario);
            ActividadUser.setIdActividad(idActividad);
            ActividadUser.guardarEnArchivo();
            std::cout << "Usuario inscrito en la actividad " << idActividad << std::endl;
            break;

            case 2:
                cout<<"\n";
                cout << "Seleccionaste: Cancelar inscripción" << endl;
                // Agrega el código para cancelar inscripción
                int idUsuariocancelar;
                int idActividadecancelar;
                cout << "Ingrese el ID del usuario a eliminar: ";
                cin >> idUsuariocancelar;
                cout << "Ingrese el ID de la actividad a la que esta inscrito: ";
                cin>> idActividadecancelar;
                ActividadesUsuarios::cancelarInscripcion(idUsuariocancelar,idActividadecancelar);
                break;

            case 3:
                cout<<"\n";
                cout << "Seleccionaste: Ver actividades disponibles" << endl;
                // Agrega el código para ver actividades disponibles
                ActividadesAcademicas::MostrarTodasActividades();
                break;
           case 4:
		cout<<"\n";
                cout <<"Seleccionaste: Ver lista usuarios inscritos:" << endl;
                ActividadesUsuarios::mostrarArchivo();
                break;
	   case 5:
		cout<<"\n";
                cout << "Volviendo al menú principal." << endl;
                break;

            default:
                cout<<"\n";
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }

    } while (opcionUsuario != 5);
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
                cout<<"\n";
                cout << "¡Bienvenido, Organizador!" << endl;
                menuOrganizador();
                break;

            case 2:
                cout<<"\n";
                cout << "¡Hola, Director Academico!" << endl;
                menuDirectorAcademico();
                break;

            case 3:
                cout<<"\n";
                cout << "¡Hola, Usuario!" << endl;
                menuUsuario();
                break;

            case 4:
                cout<<"\n";
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout<<"\n";
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}
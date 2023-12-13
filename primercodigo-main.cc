#include "actividadesAcademicas.h"
#include "actividadesAcademicas.cc"

int main() {
    int opcion;

    do {
        cout << "\nMenú:\n";
        cout << "1. Crear actividad\n";
        cout << "2. Eliminar actividad\n";
        cout << "3. Modificar actividad\n";
        cout << "4. Mostrar todas las actividades\n";
        cout << "0. Salir\n";
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                CrearActividad();
                break;

            case 2:
                int idEliminar;
                cout << "Ingrese el ID de la actividad a eliminar: ";
                cin >> idEliminar;
                ActividadesAcademicas::EliminarActividadPorID(idEliminar);
                break;

            case 3:
                
                int idModificar;
                cout << "Ingrese el ID de la actividad a modificar: ";
                cin >> idModificar;
                ActividadesAcademicas::ModificarActividadPorID(idModificar);
                break;
            
                break;

            case 4:

                ActividadesAcademicas::MostrarTodasActividades();
                break;

            case 0:
                cout << "Saliendo del programa.\n";
                break;

            default:
                cout << "Opción no válida. Inténtelo de nuevo.\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}
test

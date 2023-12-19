#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"


void testCancelarInscripcion() {
    // Crear un objeto ActividadesUsuarios (asegúrate de que esta instancia esté en un estado conocido)
    ActividadesUsuarios actividadUsuario;

    // Supongamos que tienes un archivo "usuariosinscritos.txt" con una inscripción existente
    std::ofstream archivoEntrada("usuariosinscritos.txt");
    archivoEntrada << "ID Usuario: 1, ID Actividad: 101\n";
    archivoEntrada.close();

    // Ejecutar la función cancelarInscripcion para la inscripción existente
    std::stringstream output;
    ide_listener<> listener(output);
    cancelarInscripcion(1, 101);  // Asegúrate de que estos valores coincidan con la inscripción en el archivo

    // Verificar que la salida del programa indica que la inscripción se canceló correctamente
    ASSERT_EQUAL("Inscripción cancelada correctamente.", output.str().substr(1, 36));
}
// cancelarInscripcion.cc
#include "gtest/gtest.h"
#include "ActividadesUsuarios.h"

// Prueba para la función cancelarInscripcion
TEST(ActividadesUsuariosTest, CancelarInscripcion) {
    // Crea una instancia de ActividadesUsuarios con datos ficticios
    ActividadesUsuarios inscripcion(1, 100);

    // Llama a la función cancelarInscripcion con los datos ficticios
    inscripcion.cancelarInscripcion(1, 100);

    // Verifica el comportamiento esperado
    EXPECT_EQ(-1, inscripcion.getIdUsuario());
}

// Otras pruebas para la clase ActividadesUsuarios
TEST(ActividadesUsuariosTest, OtrasPruebas) {
    // Agrega más pruebas según sea necesario
    ActividadesUsuarios inscripcion(2, 200);
    EXPECT_EQ(200, inscripcion.getIdActividad());
    // ... otras verificaciones ...
}

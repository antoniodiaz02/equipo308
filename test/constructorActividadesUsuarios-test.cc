// actividadesUsuarios-test.cc
#include "gtest/gtest.h"
#include "../actividadesUsuarios.cc"

// Test del constructor parametrizado de ActividadesUsuarios
TEST(ActividadesUsuariosTest, ConstructorParametrizado) {
    // Parámetros de prueba
    int id_usuario = 1;
    int id_actividad = 101;
    std::string fechaInscripcion = "2023-01-01";

    // Crear una instancia de ActividadesUsuarios utilizando el constructor parametrizado
    ActividadesUsuarios actividadesUsuarios(id_usuario, id_actividad, fechaInscripcion);

    // Verificar que los miembros se hayan inicializado correctamente
    EXPECT_EQ(actividadesUsuarios.getIdUsuario(), id_usuario);
    EXPECT_EQ(actividadesUsuarios.getIdActividad(), id_actividad);
    EXPECT_EQ(actividadesUsuarios.getFechaInscripcion(), fechaInscripcion);
}

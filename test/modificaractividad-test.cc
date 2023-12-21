/*
// modificarActividad-test.cc
#include "gtest/gtest.h"
#include "../actividadesAcademicas.cc"

// Prueba para la función modificarActividad
TEST(ActividadesAcademicasTest, ModificarActividadPorID) {
    // Crear una instancia de ActividadesAcademicas con datos ficticios
    ActividadesAcademicas actividad(1, "Actividad1", "2023-01-01", "Tematica1", 50, "Ubicacion1", 20.0, "Tipo1", 101);

    // Modificar algunos atributos
    modificarActividad("Nueva Actividad", "2023-02-01", "Nueva Tematica", 75, "Nueva Ubicacion", 30.0, "Nuevo Tipo", 102);

    // Verificar que los atributos se han modificado correctamente
    EXPECT_EQ("Nueva Actividad", actividad.getNombre());
    EXPECT_EQ("2023-02-01", actividad.getFecha());
    EXPECT_EQ("Nueva Tematica", actividad.getTematica());
    EXPECT_EQ(75, actividad.getAforo());
    EXPECT_EQ("Nueva Ubicacion", actividad.getUbicacion());
    EXPECT_EQ(30.0, actividad.getPrecio());
    EXPECT_EQ("Nuevo Tipo", actividad.getTipo());
    EXPECT_EQ(102, actividad.getIdDirector());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
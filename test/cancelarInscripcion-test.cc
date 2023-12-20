// cancelarInscripcion.cc
#include "gtest/gtest.h"
#include "../ActividadesUsuarios.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"

// Prueba para la función cancelarInscripcion
TEST(ActividadesUsuariosTest, CancelarInscripcion) {
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 1 QUE ES PARA CANCELAR INSCRIPCION" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    // Crea una instancia de ActividadesUsuarios con datos ficticios
    ActividadesUsuarios inscripcion(1, 100);

    // Llama a la función cancelarInscripcion con los datos ficticios
    inscripcion.guardarEnArchivo();
    inscripcion.cancelarInscripcion(1, 100);

    // Verifica el comportamiento esperado
    EXPECT_EQ(1, inscripcion.getIdUsuario());

    // Crea una instancia de ActividadesUsuarios con datos ficticios
    ActividadesUsuarios inscripcion2(2, 200);

    // Llama a la función cancelarInscripcion con los datos ficticios
    inscripcion2.guardarEnArchivo();
    inscripcion2.cancelarInscripcion(2, 200);

    // Verifica el comportamiento esperado
    EXPECT_EQ(2, inscripcion2.getIdUsuario());

    ActividadesUsuarios inscripcion3(3, 300);

    // Llama a la función cancelarInscripcion con los datos ficticios
    inscripcion3.guardarEnArchivo();
    inscripcion3.cancelarInscripcion(3, 300);

    // Verifica el comportamiento esperado
    EXPECT_EQ(3, inscripcion3.getIdUsuario());

    ActividadesUsuarios inscripcion4(4, 400);

    // Llama a la función cancelarInscripcion con los datos ficticios
    inscripcion4.guardarEnArchivo();
    inscripcion4.cancelarInscripcion(4, 400);

    // Verifica el comportamiento esperado
    EXPECT_EQ(4, inscripcion4.getIdUsuario());

    ActividadesUsuarios inscripcion5(5, 500);

    // Llama a la función cancelarInscripcion con los datos ficticios
    inscripcion5.guardarEnArchivo();
    inscripcion5.cancelarInscripcion(5, 500);

    // Verifica el comportamiento esperado
    EXPECT_EQ(5, inscripcion5.getIdUsuario());
}


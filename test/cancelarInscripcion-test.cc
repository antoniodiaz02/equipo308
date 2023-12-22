#include "gtest/gtest.h"
#include "../ActividadesUsuarios.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"

// Prueba para la función cancelarInscripcion
TEST(ActividadesUsuariosTest, CancelarInscripcion) {
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 1 QUE ES PARA CANCELAR INSCRIPCION" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    ActividadesUsuarios inscripcion(1, 100);

    inscripcion.guardarEnArchivo();
    inscripcion.cancelarInscripcion(1, 100);


    EXPECT_EQ(1, inscripcion.getIdUsuario());

    // Crea una instancia de ActividadesUsuarios con datos ficticios
    ActividadesUsuarios inscripcion2(2, 200);

    inscripcion2.guardarEnArchivo();
    inscripcion2.cancelarInscripcion(2, 200);


    EXPECT_EQ(2, inscripcion2.getIdUsuario());

    ActividadesUsuarios inscripcion3(3, 300);

    inscripcion3.guardarEnArchivo();
    inscripcion3.cancelarInscripcion(3, 300);


    EXPECT_EQ(3, inscripcion3.getIdUsuario());

    ActividadesUsuarios inscripcion4(4, 400);

    inscripcion4.guardarEnArchivo();
    inscripcion4.cancelarInscripcion(4, 400);


    EXPECT_EQ(4, inscripcion4.getIdUsuario());

    ActividadesUsuarios inscripcion5(5, 500);

    inscripcion5.guardarEnArchivo();
    inscripcion5.cancelarInscripcion(5, 500);


    EXPECT_EQ(5, inscripcion5.getIdUsuario());
}


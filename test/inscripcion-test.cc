#include "gtest/gtest.h"
#include "../ActividadesUsuarios.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"

TEST(ActividadesUsuariosTest, guardarEnArchivo) {
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 3 QUE ES PARA INSCRIPCION" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    ActividadesUsuarios inscripcion(1, 100);

    inscripcion.guardarEnArchivo();

    EXPECT_EQ(1, inscripcion.getIdUsuario());

    ActividadesUsuarios inscripcion2(2, 200);

    inscripcion2.guardarEnArchivo();

    EXPECT_EQ(2, inscripcion2.getIdUsuario());

    ActividadesUsuarios inscripcion3(3, 300);

    inscripcion3.guardarEnArchivo();

    EXPECT_EQ(3, inscripcion3.getIdUsuario());

    ActividadesUsuarios inscripcion4(-4, -4400);

    inscripcion4.guardarEnArchivo();

    EXPECT_EQ(-4, inscripcion4.getIdUsuario());

}


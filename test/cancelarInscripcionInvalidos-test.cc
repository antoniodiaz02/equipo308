#include "gtest/gtest.h"
#include "../ActividadesUsuarios.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"

TEST(ActividadesUsuariosTest, CancelarInscripcionDatosInvalidos) {
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 2: CANCELAR INSCRIPCION CON DATOS INVÁLIDOS" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;

    ActividadesUsuarios inscripcionInvalida(6, 600);

    inscripcionInvalida.guardarEnArchivo();
    inscripcionInvalida.cancelarInscripcion(-1, 600);

    EXPECT_EQ(-1, inscripcionInvalida.getIdUsuario());

    ActividadesUsuarios inscripcionInvalida2(7, 700);

    inscripcionInvalida2.guardarEnArchivo();
    inscripcionInvalida2.cancelarInscripcion(7, 1000000);

    EXPECT_EQ(-1, inscripcionInvalida2.getIdUsuario());
}

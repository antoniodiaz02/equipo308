#include "gtest/gtest.h"
#include "../ActividadesUsuarios.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"

// Prueba para la función cancelarInscripcion con datos inválidos
TEST(ActividadesUsuariosTest, CancelarInscripcionDatosInvalidos) {
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 3: CANCELAR INSCRIPCION CON DATOS INVÁLIDOS" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;

    // Crea una instancia de ActividadesUsuarios con datos ficticios
    ActividadesUsuarios inscripcionInvalida(6, 600);

    // Llama a la función cancelarInscripcion con datos inválidos (idUsuario negativo)
    inscripcionInvalida.guardarEnArchivo();
    inscripcionInvalida.cancelarInscripcion(-1, 600);

    // Verifica que el idUsuario sea -1
    EXPECT_EQ(-1, inscripcionInvalida.getIdUsuario());

    // Crea otra instancia de ActividadesUsuarios con datos ficticios
    ActividadesUsuarios inscripcionInvalida2(7, 700);

    // Llama a la función cancelarInscripcion con datos inválidos (idActividad demasiado grande)
    inscripcionInvalida2.guardarEnArchivo();
    inscripcionInvalida2.cancelarInscripcion(7, 1000000);

    // Verifica que el idUsuario sea -1
    EXPECT_EQ(-1, inscripcionInvalida2.getIdUsuario());
}

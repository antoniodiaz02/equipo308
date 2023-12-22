#include "gtest/gtest.h"
#include "../actividadesAcademicas.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"


TEST(ActividadesAcademicasTest, ActividadesAcademicasValoresNegativos) {
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 6: ACTIVIDADES ACADEMICAS CON VALORES NEGATIVOS" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;

    int id = 2;
    std::string nombre = "Actividad2";
    std::string fecha = "2023-02-01";
    std::string tematica = "Tematica2";
    int aforo = -10;  // Valor negativo
    std::string ubicacion = "Ubicacion2";
    float precio = -5.0;  // Valor negativo
    std::string tipo = "Tipo2";
    int id_director = 102;


    ActividadesAcademicas actividadNegativa(id, nombre, fecha, tematica, aforo, ubicacion, precio, tipo, id_director);

    EXPECT_EQ(id, actividadNegativa.getIdActividad());
    EXPECT_EQ(nombre, actividadNegativa.getNombre());
    EXPECT_EQ(fecha, actividadNegativa.getFecha());
    EXPECT_EQ(tematica, actividadNegativa.getTematica());
    EXPECT_EQ(0, actividadNegativa.getAforo());  
    EXPECT_EQ(ubicacion, actividadNegativa.getUbicacion());
    EXPECT_EQ(0.0, actividadNegativa.getPrecio());  
    EXPECT_EQ(tipo, actividadNegativa.getTipo());
    EXPECT_EQ(id_director, actividadNegativa.getIdDirector());
}

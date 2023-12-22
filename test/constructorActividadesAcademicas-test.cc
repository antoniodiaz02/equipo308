#include "gtest/gtest.h"
#include "../actividadesAcademicas.h"
#define ANSI_COLOR_BLUE "\033[1;34m"
#define ANSI_COLOR_RESET "\033[0m"

TEST(ActividadesAcademicasTest, ActividadesAcademicas) {
    
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "EMPEZANDO TEST 5 QUE ES PARA PROBAR EL CONSTRUCTOR DE ACTIVIDADES ACADEMICAS" << ANSI_COLOR_RESET << std::endl;
    std::cout << ANSI_COLOR_BLUE << "---------------------" << ANSI_COLOR_RESET << std::endl;

    int id = 1;
    std::string nombre = "Actividad1";
    std::string fecha = "2023-01-01";
    std::string tematica = "Tematica1";
    int aforo = 50;
    std::string ubicacion = "Ubicacion1";
    float precio = 20.0;
    std::string tipo = "Tipo1";
    int id_director = 101;

    ActividadesAcademicas actividad(id, nombre, fecha, tematica, aforo, ubicacion, precio, tipo, id_director);

    EXPECT_EQ(id, actividad.getIdActividad());
    EXPECT_EQ(nombre, actividad.getNombre());
    EXPECT_EQ(fecha, actividad.getFecha());
    EXPECT_EQ(tematica, actividad.getTematica());
    EXPECT_EQ(aforo, actividad.getAforo());
    EXPECT_EQ(ubicacion, actividad.getUbicacion());
    EXPECT_EQ(precio, actividad.getPrecio());
    EXPECT_EQ(tipo, actividad.getTipo());
    EXPECT_EQ(id_director, actividad.getIdDirector());
}
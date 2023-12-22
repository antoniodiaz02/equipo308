cmake_minimum_required(VERSION 3.12)
project(equipo308)

# Buscar Google Test
find_package(GTest REQUIRED)

# Configurar los archivos fuente y de prueba
set(SOURCES
    ActividadesUsuarios.cc
    ActividadesUsuarios.h
    actividadesAcademicas.cc
    actividadesAcademicas.h
    # Agrega tus otros archivos fuente aquí
)

set(TEST_SOURCES
    test/cancelarInscripcion-test.cc
    test/inscripcion-test.cc
    test/constructorActividadesAcademicas-test.cc
    test/cancelarInscripcionInvalidos-test.cc
    test/inscripcionInvalidos-test.cc
    test/constructorActividadesAcademicasInvalidos-test.cc
    # Agrega otros archivos de prueba aquí
)

# Agregar los ejecutables de prueba
add_executable(Test ${TEST_SOURCES} ${SOURCES})

# Configurar la inclusión de Google Test
target_include_directories(Test PRIVATE ${GTEST_INCLUDE_DIRS})

# Configurar los enlaces con Google Test
target_link_libraries(Test PRIVATE ${GTEST_BOTH_LIBRARIES})


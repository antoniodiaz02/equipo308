#include "MailingList.h"
#include <iostream>
#include <fstream>
#include <limits>

void MailingList::agregarCorreo(const std::string& correo) {
    correos.push_back(correo);
}


void MailingList::crearMailing() {
    std::cout << "¿Cuántos correos quieres añadir? ";
    int numCorreos;
    std::cin >> numCorreos;

    // Limpiar el buffer de entrada
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Pedir y agregar cada correo al vector
    for (int i = 0; i < numCorreos; ++i) {
        std::string correo;
        std::cout << "Ingrese el correo " << i + 1 << ": ";
        std::getline(std::cin, correo);
        agregarCorreo(correo);
    }

    // Pedir el nombre del archivo
    std::string nombreArchivo;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> nombreArchivo;

    // Abrir el archivo para escritura
    std::ofstream archivo(nombreArchivo.c_str());

    // Escribir los correos en el archivo
    for (const auto& correo : correos) {
        archivo << correo << "\n";
    }

    // Cerrar el archivo
    archivo.close();

    std::cout << "Mailing creado y guardado en " << nombreArchivo << std::endl;
}


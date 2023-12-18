#ifndef MAILINGLIST_H
#define MAILINGLIST_H

#include <vector>
#include <string>

class MailingList {
private:
    std::vector<std::string> correos;

public:
    void agregarCorreo(const std::string& correo);
    void crearMailing();
};

#endif // MAILINGLIST_H

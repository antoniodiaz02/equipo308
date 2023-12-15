#ifndef USUARIO_H
#define USUARIO_H


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Usuario{
    private:
        string nombre_;
        int idUsuario_;
        string email_;
    public:
        //Constructor Copia
        Usuario(Usuario const & aux){
            nombre_=aux.nombre_;
            idUsuario_=aux.idUsuario_;
            email_=aux.email_;
        }
        //Obseravdores y modificadores
            //Observadores
            string getNombre(){
                return nombre_;
            }

            string getEmail(){
                return email_;
            }
            int getID(){
                return idUsuario_;
            }

            //Modificadores
            void setNombre(string nombre){
                nombre_=nombre;
            }

            void setID(int id){
                idUsuario_=id;
            }

            void setEmail(string mail){
                email_=mail;
            }
        


};




#endif
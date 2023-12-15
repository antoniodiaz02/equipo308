#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H


#include "usuario.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

class Lista{
    private:
        int aforo_;
        vector<Usuario> v;
        int idActividad;
    public:
        //Constructor copia
        Lista(Lista const & aux){
            aforo_=aux.aforo_;
        }

        //Observadores y modificadores
            //Observadores
            int getAforo(){
                return aforo_;
            }

            //Modificadores
            void setAforo(int aforo){
                aforo_=aforo;
            }
        //funcion que añade al vector
        void añadirUsuario(int idActividad,int ){}
};


#endif
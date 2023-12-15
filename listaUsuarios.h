#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H


#include "usuario.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <iostream>
#include "actividadesAcademicas.h"

using namespace std;

class Lista{
    private:
        int aforo_;
        list<Usuario> v;
        int idActividad_;
    public:
        //Constructor copia
        Lista(Lista const & aux){
            aforo_=aux.aforo_;
            idActividad_=aux.idActividad_;
        }

        //Observadores y modificadores
            //Observadores
            int getAforo(){
                return aforo_;
            }

            int getIDActividad(){
                return idActividad_;
            }


            //Modificadores
            void setAforo(int aforo){
                aforo_=aforo;
            }

            void setIDActividad(int idActividad){
                idActividad_=idActividad;
            }
        //funcion que comprueba si el usuario esta dentro de la actividad o no
        bool usuarioAñadido(const Usuario& usuario, const std::vector<Usuario>& listaUsuarios) {
            for (const Usuario& usuarioExistente : listaUsuarios) {
                if (usuarioExistente.getID() == Usuario.getID()) {
                    return true;
                }
            }   
            return false;
        }
        //funcion que añade al vector un nuevo usuario 
        bool añadirUsuarioActividad(int idActividad,int idUsuario){
            if(idActividad!=getIDActividad()){
                return false;
            }

            for(auto it = v.begin();it!=v.end();it++){
                if(it->getID()==idUsuario){
                    return false;
                }
            }

            if()
        }
};


#endif
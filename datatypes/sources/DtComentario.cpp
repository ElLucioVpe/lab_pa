//
// Created by lucianoporta on 6/27/2019.
//

#include "../headers/DtComentario.h"

DtComentario::DtComentario(){
}

DtComentario::DtComentario(int _id, string _texto, DtUsuario _user){
   this->id=_id;
   this->texto=_texto;
   this->user = _user
}

int DtComentario::getId(){
   return this->id;
}

string DtComentario::getTexto(){
   return this->texto;
}

DtUsuario DtComentario::getDtUsuario(){
   return this->user;
}

DtComentario::~DtComentario()
{
}

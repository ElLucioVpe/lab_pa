//
// Created by lucianoporta on 6/27/2019.
//

#include "../headers/DtComentario.h"

DtComentario::DtComentario(){
}

DtComentario::DtComentario(int _id, string _texto){
   this->id=_id;
   this->texto=_texto;
}

int DtComentario::getId(){
   return this->id;
}

string DtComentario::getTexto(){
   return this->texto;
}

DtComentario::~DtComentario()
{
}

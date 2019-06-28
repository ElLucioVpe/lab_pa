//
// Created by lucianoporta on 6/27/2019.
//

#include "../headers/DtComentario.h"
#include <cstdlib>

DtComentario::DtComentario(){
}

DtComentario::DtComentario(int _id, string _texto){
   this->id=_id;
   this->texto=_texto;
}

string DtPelicula::getId(){
   return this->id;
}

string DtPelicula::getTexto(){
   return this->texto;
}

DtPelicula::~DtPelicula()
{
}

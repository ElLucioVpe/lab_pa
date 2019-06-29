//
// Created by Xavel on 29/06/2019.
//
#include "../headers/DtPuntaje.h"

DtPuntaje::DtPuntaje(){

}

DtPuntaje::DtPuntaje(int _valor, DtUsuario _user){
    this->Valor=_valor;
	this->user = _user;
}

int DtPuntaje::getValor(){
    return this->Valor;
}

DtUsuario DtPuntaje::getDtUsuario(){
    return this->user;
}

DtPuntaje::~DtPuntaje()
{
}


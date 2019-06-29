#include "../headers/Puntaje.h"

Puntaje::Puntaje(int Valor, Usuario* user){
	this->Valor= Valor;
  this->_usuario=user;
}

int Puntaje::getValor(){
	return this->Valor;
}

void Puntaje::setValor(int v){
	this->Valor= v;
}

Usuario * Puntaje::getUsuario(){
    return this->_usuario;
}

Puntaje::~Puntaje()
{

}

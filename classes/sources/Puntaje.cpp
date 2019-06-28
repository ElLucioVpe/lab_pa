#include "../headers/Puntaje.h"

Puntaje::Puntaje(int Valor,Pelicula* peli,Usuario* user){
	this->Valor= Valor;
  this->_pelicula=peli;
  this->_usuario=user;
}

int Puntaje::getValor(){
	return this->Valor;
}

void Puntaje::setValor(int v){
	this->Valor= v;
}

Puntaje::~Puntaje()
{

}

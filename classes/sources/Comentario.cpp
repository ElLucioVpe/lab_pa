#include "../headers/Comentario.h"

Comentario::Comentario(String Texto){
	this->Texto= Texto;
}

int Comentario::getTexto(){
	return this->Texto;
}

void Comentario::setTexto(String t){
	this->Texto= t;
}

Comentario::~Comentario()
{

}

#include "../headers/Comentario.h"

Comentario::Comentario(int id, string Texto){
	this->Id = id;
	this->Texto= Texto;
	hijos = new ColComentarios();
}

int Comentario::getId()
{
	return this->Id;
}

string Comentario::getTexto(){
	return this->Texto;
}

void Comentario::setId(int _id)
{
	this->Id = _id;
}

void Comentario::setTexto(string t){
	this->Texto= t;
}

void Comentario::agregarHijo(Comentario* c)
{
	hijos->add(new KeyInteger(c->Id), c);
}

Comentario::~Comentario()
{

}

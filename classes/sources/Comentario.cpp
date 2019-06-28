#include "../headers/Comentario.h"

Comentario::Comentario(int id, string Texto, Usuario* user){
	this->Id = id;
	this->Texto= Texto;
	this->Usuario= user;
	hijos = new ColComentarios();
}

int Comentario::getId()
{
	return this->Id;
}

string Comentario::getTexto(){
	return this->Texto;
}

Usuario Comentario::getUsuario(){
	return this->Usuario;
}

void Comentario::setId(int _id)
{
	this->Id = _id;
}

void Comentario::setTexto(string t){
	this->Texto= t;
}

void Comentario::setUsuario(string u){
	this->Usuario= u;
}

void Comentario::agregarHijo(Comentario* c)
{
	hijos->add(new KeyInteger(c->Id), c);
}

Comentario::~Comentario()
{

}

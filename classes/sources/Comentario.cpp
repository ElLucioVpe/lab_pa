#include "../headers/Comentario.h"

Comentario::Comentario(int id, string Texto, Usuario* autor){
	this->Id = id;
	this->Texto = Texto;
	this->Autor = autor;
	hijos = new OrderedDictionary();
}

int Comentario::getId()
{
	return this->Id;
}

string Comentario::getTexto(){
	return this->Texto;
}

Usuario* Comentario::getAutor(){
	return this->Autor;
}

void Comentario::setId(int _id)
{
	this->Id = _id;
}

void Comentario::setTexto(string t){
	this->Texto= t;
}

void Comentario::setUsuario(Usuario* u){
	this->Autor = u;
}

void Comentario::agregarHijo(Comentario* c)
{
	hijos->add(new KeyInteger(c->Id), c);
}

ICollection* Comentario::ListarHijos(string c) {
    ICollection* dts = new List();
    ComentarioIterator it = hijos->getIterator();
    while (it.hasCurrent()) {
        Comentario* c = it.getCurrent();
        Usuario* u = c->getAutor();
        dts->add(new DtComentario(c->getId(), c->getTexto(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin())));
        it.next();
    }

    return dts;
}

Comentario::~Comentario()
{

}

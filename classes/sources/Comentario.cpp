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

void Comentario::agregarHijo(vector<int> padres, Comentario* c)
{
	//padres existe por si es hijo de otro hijo
	if (padres.size() == 0) {
		//Es simplemente un hijo
		c->setId(hijos->getSize()+1); //Reemplazo el 0 por la id correspondiente
		hijos->add(new KeyInteger(c->getId()), c);
	}
	else {
		Comentario* cpadre = dynamic_cast<Comentario*>(hijos->find(new KeyInteger(padres[0])));

		if (cpadre == NULL) throw std::invalid_argument("El comentario no existe");

		padres.erase(padres.begin());
		cpadre->agregarHijo(padres, c);
	}
}

ICollection* Comentario::ListarHijos() {
    ICollection* dts = new List();

	if (!hijos->isEmpty()) {
		IIterator* it = hijos->getIterator();
		while (it->hasCurrent()) {
			Comentario* c = dynamic_cast<Comentario*>(it->getCurrent());
			Usuario* u = c->getAutor();
			ICollection* hijosdt = c->ListarHijos();
			dts->add(new DtComentario(c->getId(), c->getTexto(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin()), hijosdt));
			it->next();
		}
	}
	return dts;
}

Comentario::~Comentario()
{

}

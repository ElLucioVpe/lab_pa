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

IDictionary* Comentario::getHijos() {
   return this->hijos;
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
		Comentario* c = dynamic_cast<Comentario*>(hijos->find(new KeyInteger(padres[0])));
		padres.erase(padres.begin());
		c->agregarHijo(padres, c);
	}
}

ICollection * Comentario::getComentario(IDictionary* hijo){
   if (hijo->isEmpty()) return nullptr;
   ICollection * dts= new List();
   IIterator* it = hijo->getIterator();
   while (it->hasCurrent()) {
      Comentario *c = dynamic_cast<Comentario *>(it->getCurrent());
      Usuario* u = c->getAutor();
      dts->add(new DtComentario(c->getId(), c->getTexto(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin()), c->getComentario(c->getHijos())));
      it->next();

   }

   return dts;
}

ICollection* Comentario::ListarHijos() {
    ICollection* dts = new List();
    IIterator* it = hijos->getIterator();
    while (it->hasCurrent()) {
        Comentario* c = dynamic_cast<Comentario*>(it->getCurrent());
        Usuario* u = c->getAutor();
        dts->add(new DtComentario(c->getId(), c->getTexto(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin()), c->ListarHijos()));
        it->next();
    }

    return dts;
}

Comentario::~Comentario()
{

}

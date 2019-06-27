#include "../headers/Cine.h"
Cine::Cine(int IdCine, string Direccion){
	this->IdCine= IdCine;
	this->Direccion= Direccion;
	salas = new ColSalas();

}
int Cine::getIdCine() {
	return this->IdCine;
}
string Cine::getDireccion(){
	return this->Direccion;
}
void Cine::setDireccion(string Direccion){
	this->Direccion = Direccion;
}
void Cine::setIdCine(int idCine){
	this->IdCine = idCine;
}

ICollection* Cine::ListarSalas()
{
	ICollection* dts = new List();
	SalaIterator it = salas.getIterator();
	while (it.hasCurrent()) {
		Sala* s = it.getCurrent();
		dts->add(new DtSala(s->getIdSala(), s->getCantAsientos()));

		it.next();
	}

	return dts;
}


Cine::~Cine()
{

}

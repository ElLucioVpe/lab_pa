#include "../headers/Pelicula.h"


Pelicula::Pelicula(string titulo, string poster, string sinopsis, float puntaje){
  this->titulo=titulo;
  this->poster=poster;
  this->sinopsis=sinopsis;
  this->puntaje=puntaje;
}
string Pelicula::getTitulo(){
    return this->titulo;
}
string Pelicula::getPoster(){
    return this->poster;
}
string Pelicula::getSinopsis(){
    return this->sinopsis;
}
float Pelicula::getPuntaje(){
    return this->puntaje;
}
void Pelicula::setTitulo(string titulo){
	this->titulo=titulo;
}
void Pelicula::setPoster(string Poster) {
	this->poster = Poster;
}
void Pelicula::setSinopsis(string sinopsis){
	this->sinopsis=sinopsis;
}
void Pelicula::setPuntaje(float puntaje){
	this->puntaje=puntaje;
}

void Pelicula::CrearReserva(int cantAsientos, float costo, int idFuncion, Usuario* u, string banco, string financiera)
{
	Funcion* f = funciones.find(new KeyInteger(idFuncion));
	f->ReservarFuncion(cantAsientos, costo, u->getNickname(), banco, financiera);
}

void Pelicula::EliminarFunciones()
{
	FuncionIterator it = funciones.getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		f->~Funcion();
		it.next();
	}
}

ICollection* Pelicula::ListarFunciones()
{
	ICollection* dts;
	FuncionIterator it = funciones.getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		dts->add(new DtFuncion(f->getIdFuncion(), f->getHorario()));
		it.next();
	}

	return dts;
}

ICollection* Pelicula::getCines()
{
	ICollection* dts = NULL;
	FuncionIterator it = funciones.getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		dts->add(new DtCine(f->getCines()->getIdCine(), f->getCines()->getDireccion()));
		it.next();
	}

	return dts;
}

Pelicula::~Pelicula() {
	EliminarFunciones();
}

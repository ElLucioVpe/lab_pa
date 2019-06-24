#include "../headers/Pelicula.h"
#include <cstdlib>

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

void Pelicula::EliminarFunciones()
{
	FuncionIterator it = funciones.getIterator();
	Funcion* f;
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		f->~Funcion();
		it.next();
	}
}

/*set<DtFuncion> Pelicula::ListarFunciones()
{
	set<DtFuncion> dts;
	FuncionIterator it = funciones.getIterator();
	Funcion* f;
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		dts.insert(DtFuncion(f->getIdFuncion(), f->getHorario()));
		it.next();
	}

	return dts;
}*/

set<DtCine> Pelicula::getCines()
{
	set<DtCine> dts;
	FuncionIterator it = funciones.getIterator();
	Funcion* f;
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		dts.insert(DtCine(f->getCines()->getIdCine(), f->getCines()->getDireccion()));
		it.next();
	}

	return dts;
}

Pelicula::~Pelicula() {
	EliminarFunciones();
}

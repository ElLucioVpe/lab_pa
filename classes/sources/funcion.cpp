#include "../headers/Funcion.h"
#include <cstdlib>

Funcion::Funcion(int IdFuncion, string Horario ){
	this->IdFuncion= IdFuncion;
	this->Horario= Horario;
}
int Funcion::getIdFuncion(){
	return this->IdFuncion;
}
string Funcion::getHorario(){
	return this->Horario;
}
Cine* Funcion::getCines(){
	return this->cine;
}
void Funcion::setIdfuncion(int IdFuncion){
	this->IdFuncion= IdFuncion;
}
void Funcion::setHorario(string Horario){
	this->Horario= Horario;
}
void Funcion::EliminarReservas() {
	reservas.~ColReservas();
}
bool Funcion::EsDePelicula(string t) {
	return pelicula->getTitulo() == t;
}
void Funcion::ReservarFuncion(int cantAsientos, float costo, string usuario) {
	reservas.add(new Reserva(costo, cantAsientos));
	//se necesita agregar un parametro Usuario a Reserva o alguna otra forma de saber quien la reservo 
}

Funcion::~Funcion()
{
	EliminarReservas();
}

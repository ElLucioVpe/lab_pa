#include "../headers/Funcion.h"
#include "../headers/TarjetaDeCredito.h"
#include "../headers/TarjetaDeDebito.h"

Funcion::Funcion(int IdFuncion, string Horario){
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
	return this->_cine;
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
	return true;//No es necesaria si la busqueda empieza desde la pelicula
}
void Funcion::ReservarFuncion(int cantAsientos, float costo, string usuario, string banco, string financiera) {
	
	if (banco == "") reservas.add(new TarjetaDeCredito(financiera, costo, cantAsientos));
	else reservas.add(new TarjetaDeDebito(banco, costo, cantAsientos));

	//se necesita agregar un parametro Usuario a Reserva o alguna otra forma de saber quien la reservo 
}

Funcion::~Funcion()
{
	EliminarReservas();
}

#include "../headers/Funcion.h"
#include "../headers/TarjetaDeCredito.h"
#include "../headers/TarjetaDeDebito.h"

Funcion::Funcion(int IdFuncion, string _horario){
	this->IdFuncion= IdFuncion;

	time_t horario;
	int yy, month, dd, hh, mm, ss;
	struct tm horariotm = { 0 };

	sscanf(_horario.c_str(), "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
	horariotm.tm_year = yy - 1900;
	horariotm.tm_mon = month - 1;
	horariotm.tm_mday = dd;
	horariotm.tm_hour = hh;
	horariotm.tm_min = mm;
	horariotm.tm_sec = ss;
	horariotm.tm_isdst = -1;

	horario = mktime(&horariotm);
	this->Horario= horario;
}

int Funcion::getIdFuncion(){
	return this->IdFuncion;
}

time_t Funcion::getHorario(){
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
bool Funcion::EsDeCine(int idCine)
{
	return _cine->getIdCine() == idCine;
}
void Funcion::ReservarFuncion(int cantAsientos, float costo, string usuario, string banco, string financiera) {
	
	if (banco == "") reservas.add(new TarjetaDeCredito(financiera, costo, cantAsientos));
	else reservas.add(new TarjetaDeDebito(banco, costo, cantAsientos));

	//se deberia agregar un parametro Usuario a Reserva o alguna otra forma de saber quien la reservo
}

Funcion::~Funcion()
{
	EliminarReservas();
}

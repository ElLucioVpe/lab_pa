#include "../headers/Funcion.h"
#include <cstdlib>

Funcion::Funcion(int IdFuncion, date Horario ){
	this->IdFuncion= IdFuncion;
	this->Horario= Horario;
}
int Funcion::getIdFuncion(){
	return this->IdFuncion;
}
date Funcion::getHorario(){
	return this->Horario;
}
cine Funcion::getCines(){
	return this->cine;
}
void Funcion::setIdfuncion(int IdFuncion){
	this->IdFuncion= IdFuncion;
}
void Funcion::setHorario(date Horario){
	this->Horario= Horario;
}


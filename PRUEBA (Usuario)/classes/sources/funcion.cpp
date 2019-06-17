#include "../headers/funcion.h"
#include <cstdlib>

funcion::funcion(int IdFuncion, date Horario ){
	this->IdFuncion= IdFuncion;
	this->Horario= Horario;
}
int funcion::getIdFuncion(){
	return this->IdFuncion;
}
date funcion::getHorario(){
	return this->Horario;
}
cine funcion::getCines(){
	return this->cine;
}
void funcion::setIdfuncion(int IdFuncion){
	this->IdFuncion= IdFuncion;
}
void funcion::setHorario(date Horario){
	this->Horario= Horario;
}


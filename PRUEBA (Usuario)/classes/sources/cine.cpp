#include "../headers/cine.h"
#include <cstdlib>

cine::cine(int IdCine, string Direccion){
	this->IdCine= IdCine;
	this->Direccion= Direccion;
	
} 
int cine::getIdCine() {
	return this->idCine;
	
}
string cine::getDireccion(){
	return this->Direccion;
}
void cine::setDireccion(string Direccion){
	this->Direccion=Direccion;
}
void cine::setIdCine(int idCine){
	this->idCine=idCine;
}
funcion** cine::getFunciones(){
	return this->Funciones;
}
int cine::getcantFunciones(){
	return this->cantFunciones;
}

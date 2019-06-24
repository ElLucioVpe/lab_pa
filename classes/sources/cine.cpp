#include "../headers/Cine.h"
#include <cstdlib>

Cine::Cine(int IdCine, string Direccion){
	this->IdCine= IdCine;
	this->Direccion= Direccion;
	
} 
int Cine::getIdCine() {
	return this->IdCine;
	
}
string Cine::getDireccion(){
	return this->Direccion;
}
void Cine::setDireccion(string Direccion){
	this->Direccion=Direccion;
}
void Cine::setIdCine(int idCine){
	this->IdCine=idCine;
}
ColFunciones Cine::getFunciones(){
	return this->Funciones;
}
int Cine::getcantFunciones(){
	return this->cantFunciones;
}
Cine::~Cine()
{

}


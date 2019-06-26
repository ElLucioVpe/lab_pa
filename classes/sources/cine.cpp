#include "../headers/Cine.h"

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
	this->Direccion = Direccion;
}
void Cine::setIdCine(int idCine){
	this->IdCine = idCine;
}
Cine::~Cine()
{

}


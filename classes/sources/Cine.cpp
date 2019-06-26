#include "../headers/Cine.h"

Cine::Cine(int IdCine, String Direccion){
	this->IdCine= IdCine;
	this->Direccion= Direccion;

}
int Cine::getIdCine() {
	return this->IdCine;
}
String Cine::getDireccion(){
	return this->Direccion;
}
void Cine::setDireccion(String Direccion){
	this->Direccion = Direccion;
}
void Cine::setIdCine(int idCine){
	this->IdCine = idCine;
}
Cine::~Cine()
{

}

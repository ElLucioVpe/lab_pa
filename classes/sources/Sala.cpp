#include "../headers/Sala.h"

Sala::Sala(int IdSala, int CantAsientos){
	this->IdSala= IdSala;
	this->CantAsientos= CantAsientos;

}
int Sala::getIdSala() {
	return this->IdSala;
}
int Sala::getCantAsientos(){
	return this->CantAsientos;
}
void Sala::setIdSala(int IdSala){
	this->IdSala = IdSala;
}
void Sala::setCantAsientos(int CantAsientos){
	this->CantAsientos = CantAsientos;
}
Sala::~Sala()
{

}

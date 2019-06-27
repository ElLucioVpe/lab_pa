#include "../headers/DtSala.h"

DtSala::DtSala(){

}

DtSala::DtSala(int IdSala, int CantAsientos){
    this->IdSala = idCine;
    this->CantAsientos = direccion;
}

int DtSala::getIdSala() {
	return this->IdSala;
}
int DtSala::getCantAsientos(){
	return this->CantAsientos;
}
void DtSala::setIdSala(int IdSala){
	this->IdSala = IdSala;
}
void DtSala::setCantAsientos(int CantAsientos){
	this->CantAsientos = CantAsientos;
}
DtSala::~DtSala()
{

}

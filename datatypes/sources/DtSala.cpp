#include "../headers/DtSala.h"

DtSala::DtSala(int IdSala, int CantAsientos){
    this->IdSala = IdSala;
    this->cantAsientos = CantAsientos;
}

int DtSala::getIdSala() {
	return this->IdSala;
}
int DtSala::getCantAsientos(){
	return this->cantAsientos;
}
void DtSala::setIdSala(int IdSala){
	this->IdSala = IdSala;
}
void DtSala::setCantAsientos(int CantAsientos){
	this->cantAsientos = CantAsientos;
}
DtSala::~DtSala()
{

}
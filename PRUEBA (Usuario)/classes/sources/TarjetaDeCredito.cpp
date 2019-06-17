#include "../headers/TarjetaDeCredito.h"

TarjetaDeCredito::TarjetaDeCredito(std::string _financiera, float _porcentaje) : Reserva(_prec, _cantAsientos) {
	this->Financiera = _financiera;
	this->PorcentajeDescuento = _porcentaje
}

std::string TarjetaDeCredito::getFinanciera() {
	return this->Financiera;
}

float TarjetaDeCredito::getDescuento() {
	return this->PorcentajeDescuento;
}
		
void TarjetaDeCredito::setFinanciera(std:string f) {
	this->Financiera = f;
}

void TarjetaDeCredito::setDescuento(float p) {
	this->PorcentajeDescuento = p;
}

TarjetaDeCredito::~TarjetaDeCredito() {

}
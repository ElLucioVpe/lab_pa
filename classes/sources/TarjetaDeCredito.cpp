#include "../headers/TarjetaDeCredito.h"

TarjetaDeCredito::TarjetaDeCredito(std::string _financiera, float _descuento, float _precio, int _cantAsientos, Usuario* _user) : Reserva(_precio, _cantAsientos, _user) {
	this->Financiera = _financiera;
	this->PorcentajeDescuento = _descuento;
}

std::string TarjetaDeCredito::getFinanciera() {
	return this->Financiera;
}

float TarjetaDeCredito::getDescuento() {
	return this->PorcentajeDescuento;
}
		
void TarjetaDeCredito::setFinanciera(std::string f) {
	this->Financiera = f;
}

void TarjetaDeCredito::setDescuento(int p) {
	this->PorcentajeDescuento = p;
}

TarjetaDeCredito::~TarjetaDeCredito() {

}
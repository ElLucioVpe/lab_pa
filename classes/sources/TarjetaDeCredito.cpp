#include "../headers/TarjetaDeCredito.h"

TarjetaDeCredito::TarjetaDeCredito(std::string _financiera, float _precio, int _cantAsientos) : Reserva(_precio, _cantAsientos) {
	this->Financiera = _financiera;
	//Financieras de ejemplo
	if (_financiera  == "1 SA") this->PorcentajeDescuento = 10;
	else
	{
		if (_financiera == "2 SA") this->PorcentajeDescuento = 15;
		else this->PorcentajeDescuento = 0;
	}
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

void TarjetaDeCredito::setDescuento(float p) {
	this->PorcentajeDescuento = p;
}

TarjetaDeCredito::~TarjetaDeCredito() {

}
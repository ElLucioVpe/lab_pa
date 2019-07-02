#include "../headers/DtTarjetaDeCredito.h"

DtTarjetaDeCredito::DtTarjetaDeCredito(std::string _financiera, int _descuento, float _precio, int _cantAsientos, DtUsuario user) : DtReserva(_precio, _cantAsientos, user) {
	this->Financiera = _financiera;
	this->PorcentajeDescuento = _descuento;
}

std::string DtTarjetaDeCredito::getFinanciera() {
	return this->Financiera;
}

int DtTarjetaDeCredito::getDescuento()
{
	return this->PorcentajeDescuento;
}

DtTarjetaDeCredito::~DtTarjetaDeCredito()
{

}
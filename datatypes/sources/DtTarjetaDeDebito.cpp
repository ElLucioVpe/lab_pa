#include "../headers/DtTarjetaDeDebito.h"

DtTarjetaDeDebito::DtTarjetaDeDebito(std::string _banco, float _precio, int _cantAsientos, DtUsuario user) : DtReserva(_precio, _cantAsientos, user) {
	this->Banco = _banco;
}

std::string DtTarjetaDeDebito::getBanco() {
	return this->Banco;
}

DtTarjetaDeDebito::~DtTarjetaDeDebito()
{

}
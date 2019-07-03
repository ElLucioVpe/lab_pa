#include "../headers/TarjetaDeDebito.h"

TarjetaDeDebito::TarjetaDeDebito(std::string _banco, float _precio, int _cantAsientos, Usuario* user) : Reserva(_precio, _cantAsientos, user) {
	this->Banco = _banco;
}

std::string TarjetaDeDebito::getBanco()
{
	return this->Banco;
}

TarjetaDeDebito::TarjetaDeDebito() : Reserva() {
}

TarjetaDeDebito::~TarjetaDeDebito() {
}
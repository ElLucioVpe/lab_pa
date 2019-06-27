#include "../headers/TarjetaDeDebito.h"

TarjetaDeDebito::TarjetaDeDebito(std::string _banco, float _precio, int _cantAsientos) : Reserva(_precio, _cantAsientos) {
	this->Banco = _banco;
}

TarjetaDeDebito::TarjetaDeDebito() : Reserva() {
}

TarjetaDeDebito::~TarjetaDeDebito() {
}
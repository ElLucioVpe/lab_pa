#include "../headers/TarjetaDeDebito.h"

TarjetaDeDebito(std::string _banco, int _idSala, int _cantAsientos) : Reserva(_precio, _cantAsientos) {
	this->banco = _banco;
}

TarjetaDeDebito() : Reserva(nullptr) {
}

Reserva::~Reserva() {
}
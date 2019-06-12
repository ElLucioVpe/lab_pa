#include "../headers/TarjetaDeDebito.h"

TarjetaDeDebito(std::string _banco, int _idSala, int _cantAsientos) : Reserva(_idSala, _cantAsientos) {
	this->banco = _banco;
}

TarjetaDeDebito() : Reserva(nullptr) {
}
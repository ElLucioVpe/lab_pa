#include "../headers/TarjetaDeDebito.h"

TarjetaDeDebito(std::string _banco, Reserva _reserva) : Reserva(_reserva) {
	this->banco = _banco;
}

TarjetaDeDebito() : Reserva(nullptr) {
}
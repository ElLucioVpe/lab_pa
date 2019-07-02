#include "../headers/DtReserva.h"

DtReserva::DtReserva(float _precio, int _cantAsientos, DtUsuario _user) {
	this->precio = _precio;
	this->cantidadAsientos = _cantAsientos;
	this->usuario = _user;
}

float DtReserva::getPrecio() const {
	return this->precio;
}

int DtReserva::getCantidadAsientos() const {
	return this->cantidadAsientos;
}

DtUsuario DtReserva::getUsuario() {
	return this->usuario;
}

DtReserva::~DtReserva()
{
}
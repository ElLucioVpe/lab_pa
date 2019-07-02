#include "../headers/Reserva.h"

Reserva::Reserva()
{

}

Reserva::Reserva(float prec, int cantAsientos, Usuario* user){
    this->precio = prec;
    this->cantidadAsientos = cantAsientos;
	this->usuario = user;
}

float Reserva::getPrecio() const {
    return this->precio;
}

int Reserva::getCantidadAsientos() const {
    return this->cantidadAsientos;
}

Usuario* Reserva::getUsuario()
{
	return this->usuario;
}

Reserva::~Reserva() {
}


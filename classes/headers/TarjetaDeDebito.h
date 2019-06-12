#ifndef TARJETADEDEBITO_H
#define TARJETADEDEBITO_H

#include "../headers/Reserva.h"

class TarjetaDeDebito: public Reserva {
	private:
		std::string Banco;
	public:
		TarjetaDeDebito() : Reserva();
		TarjetaDeDebito(std::string _banco, int _idSala, int _cantAsientos) : Reserva(_idSala, _cantAsientos);
}
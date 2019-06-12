#ifndef TARJETADEDEBITO_H
#define TARJETADEDEBITO_H

class TarjetaDeDebito: public Reserva {
	private:
		std::string Banco;
	public:
		TarjetaDeDebito() : Reserva();
		TarjetaDeDebito(std::string _banco, Reserva _reserva) : Reserva(_reserva) 
}
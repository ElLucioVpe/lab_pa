#ifndef TARJETADEDEBITO_H
#define TARJETADEDEBITO_H

#include <iostream>
#include "../headers/Reserva.h"

class TarjetaDeDebito : public Reserva {
private:
	std::string Banco;
public:
	TarjetaDeDebito();
	TarjetaDeDebito(std::string _banco, int _idSala, float _precio, int _cantAsientos);
	virtual ~TarjetaDeDebito();
};

#endif /* TARJETADEDEBITO_H */
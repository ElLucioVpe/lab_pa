#ifndef TARJETADEDEBITO_H
#define TARJETADEDEBITO_H

#include <iostream>
#include "../headers/Reserva.h"

class TarjetaDeDebito : public Reserva {
private:
	std::string Banco;
public:
	TarjetaDeDebito();
	TarjetaDeDebito(std::string _banco, float _precio, int _cantAsientos, Usuario* _user);
	std::string getBanco();
	virtual ~TarjetaDeDebito();
};

#endif /* TARJETADEDEBITO_H */
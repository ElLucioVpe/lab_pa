#ifndef TARJETADECREDITO_H
#define TARJETADECREDITO_H

#include "Reserva.h"
#include <iostream>

class TarjetaDeCredito : public Reserva {
private:
	std::string Financiera;
	float PorcentajeDescuento;
public:
	TarjetaDeCredito(std::string _financiera, float _descuento, float _precio, int _cantAsientos, Usuario* _user);

	std::string getFinanciera();
	float getDescuento();

	void setFinanciera(std::string f);
	void setDescuento(float p);

	~TarjetaDeCredito();
};

#endif /* TARJETADECREDITO_H */
#ifndef TARJETADECREDITO_H
#define TARJETADECREDITO_H

#include "Reserva.h"
#include <iostream>

class TarjetaDeCredito : public Reserva {
private:
	std::string Financiera;
	int PorcentajeDescuento;
public:
	TarjetaDeCredito(std::string _financiera, int _descuento, float _precio, int _cantAsientos, Usuario* _user);

	std::string getFinanciera();
	int getDescuento();

	void setFinanciera(std::string f);
	void setDescuento(int p);

	~TarjetaDeCredito();
};

#endif /* TARJETADECREDITO_H */
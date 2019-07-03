#ifndef DTTARJETADECREDITO_H
#define DTTARJETADECREDITO_H

#include <iostream>
#include <string>
#include "DtReserva.h"

class DtTarjetaDeCredito : public DtReserva {
public:
	DtTarjetaDeCredito(std::string _financiera, float _descuento, float _precio, int _cantAsientos, DtUsuario user);
	std::string getFinanciera();
	float getDescuento();
    
    virtual ~DtTarjetaDeCredito();
private:
	std::string Financiera;
	float PorcentajeDescuento;
};

#endif /* DTTARJETADECREDITO_H */
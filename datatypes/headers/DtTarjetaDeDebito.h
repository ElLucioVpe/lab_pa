#ifndef DTTARJETADEDEBITO_H
#define DTTARJETADEDEBITO_H

#include <iostream>
#include <string>
#include "DtReserva.h"

class DtTarjetaDeDebito : public DtReserva {
public:
	DtTarjetaDeDebito(std::string _banco, float _precio, int _cantAsientos, DtUsuario user);
	std::string getBanco();
    
    virtual ~DtTarjetaDeDebito();
private:
	std::string Banco;
};

#endif /* DTTARJETADEDEBITO_H */
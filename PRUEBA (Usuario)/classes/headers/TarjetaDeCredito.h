#ifndef TARJETADECREDITO_H
#define TARJETADECREDITO_H

#include "Reserva.h"
#include "string"

class TarjetaDeCredito: public Reserva {
	private:
		std::string Financiera;
		float PorcentajeDescuento;
	public:
		TarjetaDeCredito(std::string _financiera, float _porcentaje);

		std::string getFinanciera();
		float getDescuento();
		
		void setFinanciera(f);
		void setDescuento(p);

		~TarjetaDeCredito();
}

#endif /* TARJETADECREDITO_H */

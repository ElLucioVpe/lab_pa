#ifndef RESERVA_H
#define RESERVA_H

#include "../../interfaces/ICollectible.h"
#include "Usuario.h"

class Reserva : public ICollectible {
public:
	Reserva();
    Reserva(float, int, Usuario*);
    float getPrecio() const;
    int getCantidadAsientos() const;
	Usuario* getUsuario();
    
    virtual ~Reserva();
private:
    float precio;
    int cantidadAsientos;
	Usuario* usuario;
};

#endif /* RESERVA_H */


#ifndef RESERVA_H
#define RESERVA_H

#include "../../interfaces/ICollectible.h"

class Reserva : public ICollectible {
public:
	Reserva();
    Reserva(float, int);
    float getPrecio() const;
    int getCantidadAsientos() const;
    
    virtual ~Reserva();
private:
    float precio;
    int cantidadAsientos;
};

#endif /* RESERVA_H */


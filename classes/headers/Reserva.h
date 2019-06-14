#ifndef RESERVA_H
#define RESERVA_H

#include "interfaces/ICollectible.h"

class Reserva : ICollectible {
public:
    Reserva(float, int);
    float getPrecio() const;
    int getCantidadAsientos() const;
    
    virtual ~Reserva();
private:
    float precio;
    int cantidadAsientos;
};

#endif /* RESERVA_H */


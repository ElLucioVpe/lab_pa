#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <iostream>
#include <string>
#include "DtUsuario.h"
#include "../../interfaces/ICollectible.h"

class DtReserva : public ICollectible {
public:
	DtReserva(float, int, DtUsuario);
    float getPrecio() const;
    int getCantidadAsientos() const;
	DtUsuario getUsuario();
    
    virtual ~DtReserva();
private:
    float precio;
    int cantidadAsientos;
	DtUsuario usuario;
};

#endif /* DTRESERVA_H */
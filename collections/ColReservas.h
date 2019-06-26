#ifndef COLRESERVAS_H
#define	COLRESERVAS_H

#include <iostream>
#include <string>
#include "../classes/headers/Reserva.h"
#include "OrderedDictionary.h"
#include "ReservaIterator.h"
#include "../String.h"

class ColReservas{
private:
    IDictionary* reservas;

public:
    ColReservas();
    ~ColReservas();

    void add(String* k,Usuario * u);
    void remove(String* k);
    bool member(String* k);
	Reserva* find(String* k);
    bool isEmpty() const;
    int getSize() const;
    ReservaIterator getIterator();
};

#endif	/* COLRESERVAS_H */


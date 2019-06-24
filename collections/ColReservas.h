/* 
 * File:   List.h
 * Author: igui
 *
 * Created on 26 de mayo de 2012, 02:33 PM
 */

#ifndef COLRESERVAS_H
#define	COLRESERVAS_H

#include <iostream>
#include <string>
#include "../classes/headers/Reserva.h"
#include "../interfaces/ICollection.h"
#include "ReservaIterator.h"
#include "List.h"

class ColReservas{
private:
    ICollection* reservas;

public:
    ColReservas();
    ~ColReservas();

    void add(Reserva * r);
    void remove(Reserva * r);
    bool member(Reserva * r);
    bool isEmpty() const;
    int getSize() const;
    ReservaIterator getIterator();
};

#endif	/* COLRESERVAS_H */


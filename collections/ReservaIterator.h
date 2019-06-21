#ifndef RESERVAITERATOR_H
#define	RESERVAITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Reserva.h"

class ReservaIterator {
public:
	ReservaIterator();
    ReservaIterator(IIterator * listIt);
    Reserva *getCurrent();
    bool hasCurrent();
    void next();
    
    ~ReservaIterator();
private:
    IIterator *it;
};

#endif	/* RESERVAITERATOR_H */


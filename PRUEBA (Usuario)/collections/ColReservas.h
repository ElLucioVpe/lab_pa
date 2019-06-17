#ifndef COLRESERVAS_H
#define	COLRESERVAS_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Reserva.h"

/**
 *  Una lista común
 */
class ColReservas{
private:
public:

	ColReservas();
    
    void add(Reserva *);

    
    void remove(Reserva *);
    
    
    bool member(Reserva *);
    
    int getSize(Reserva *c);

	bool isEmpty(Reserva *c);
    
};

#endif	/* COLRESERVAS_H */


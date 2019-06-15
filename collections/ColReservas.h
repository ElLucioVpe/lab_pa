/* 
 * File:   List.h
 * Author: igui
 *
 * Created on 26 de mayo de 2012, 02:33 PM
 */

#ifndef LIST_H
#define	LIST_H

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
    
    
    bool member(Reserva *) const;
    
};

#endif	/* LIST_H */


/* 
 * File:   IIterator.h
 * Author: igui
 *
 * Created on 28 de mayo de 2011, 07:43 PM
 */

#include "ListIterator.h"



#ifndef ReservaIterator
#define	ReservaIterator

/** 
 * Interfaz de iteradores
 */ 
class ReservaIterator{
public:
    /**
     *  Devuelve el actual elemento de la colección en la iteración.
     *  Tira una excepción out_of_range si no hay tal elemento
     */
     ICollectible *getCurrent():ColReservas;

    /*
     *  Devuelve true si hay un elemento en la colección. 
     */
     bool hasCurrent():bool;
    
    /*
     *  Hace un paso en la iteración. Si hasCurrent() es false
     *  tira excepción out_of_range
     */
     void next();
        
};

#endif	/* ReservaIterator */


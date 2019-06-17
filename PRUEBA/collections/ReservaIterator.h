/* 
 * File:   IIterator.h
 * Author: igui
 *
 * Created on 28 de mayo de 2011, 07:43 PM
 */

#include "../interfaces/IIterator.h"
#include "../classes/headers/Reserva.h"
#include "ListNode.h"

#ifndef ReservaIterator_H
#define	ReservaIterator_H

/** 
 * Interfaz de iteradores
 */ 
class ReservaIterator{
public:

     bool hasCurrent();
 
     void next();
     
   	//virtual ~ListIterator();
        
};

#endif	/* ReservaIterator_H */


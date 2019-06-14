/* 
 * File:   List.cpp
 * Author: igui
 * 
 * Created on 26 de mayo de 2012, 02:33 PM
 */

#include "ColReservas.h"
#include "ListIterator.h"

List::List():
   head(NULL), size(0){
}

void ColReservas::add(Reserva* c)
{
ICollectible *Rese = Reserva;
add(Rese);

}

void ColReservas::remove(Reserva *c)
{
ICollectible *Rese = Reserva;
remove(Rese);
}

bool ColReservas::member(Reserva *c) const{
ICollectible *Rese = Reserva;
member(Rese);
        
}

int ColReservas::getSize() const
{
ICollectible *Rese = Reserva;
getSize(Rese);
}

bool ColReservas::isEmpty() const
{
ICollectible *Rese = Reserva;
isEmpty(Rese);
}

IIterator *ColReservas::getIterator()
{
ICollectible *Rese = Reserva;
getIterator(Rese);
}

ColReservas::~List() {

}


#include "ColReservas.h"

ColReservas::ColReservas() {
    reservas = new OrderedDictionary();
}

void ColReservas::add(String* k,Usuario * u) {
    reservas->add(r);
}

void ColReservas::remove(String* k) {
    reservas->remove(r);
}

bool ColReservas::member(String* k) {
    return reservas->member(r);
}

int ColReservas::getSize() const {
    return reservas->getSize();
}

bool ColReservas::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

ReservaIterator ColReservas::getIterator() {
	return ReservaIterator(reservas->getIterator());
}

ColReservas::~ColReservas() {
    IIterator* it = reservas->getIterator();
    while (it->hasCurrent()) {
        Reserva* temp = dynamic_cast<Reserva*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete reservas;
}

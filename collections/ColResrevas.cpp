c#include "ColReservas.h"

ColReservas::ColReservas() {
    reservas = new List();
}

void ColUsuario::add(Reserva * u) {
    reservas->add(u);
}

void ColReservas::remove(Reserva * u) {
    reservas->remove(u);
}

bool ColReservas::member(Reserva * u) {
    return reservas->member(u);
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
    //instance = nullptr;
}

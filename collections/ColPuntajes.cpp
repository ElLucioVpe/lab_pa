#include "ColPuntajes.h"

ColPuntajes::ColPuntajes() {
    puntajes = new List();
}

void ColPuntajes::add(Puntaje* p) {
	puntajes->add(p);
}

void ColPuntajes::remove(Puntaje* p) {
    puntajes->remove(p);
}

bool ColPuntajes::member(Puntaje* p) {
    return puntajes->member(p);
}

int ColPuntajes::getSize() const {
    return puntajes->getSize();
}

bool ColPuntajes::isEmpty() const {
    if (this->getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

PuntajeIterator ColPuntajes::getIterator() {
	return PuntajeIterator(puntajes->getIterator());
}

ColPuntajes::~ColPuntajes() {
    IIterator* it = puntajes->getIterator();
    while (it->hasCurrent()) {
        Puntaje* temp = dynamic_cast<Puntaje*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete puntajes;
  }

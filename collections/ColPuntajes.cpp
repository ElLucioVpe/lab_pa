#include "ColPuntajes.h"

ColPuntajes::ColPuntajes() {
    puntajes = new OrderedDictionary();
}

void ColPuntajes::add(KeyString* k,Puntaje* p) {
	puntajes->add(k,p);
}

void ColPuntajes::remove(KeyString* k) {
    comentarios->remove(k);
}

bool ColPuntajes::member(KeyString* k) {
    return comentarios->member(k);
}

Puntaje* ColPuntajes::find(KeyString* k)
{
	return dynamic_cast<Puntaje*>(puntajes->find(k));
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

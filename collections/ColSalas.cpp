#include "ColSalas.h"

ColSalas::ColSalas() {
    salas = new OrderedDictionary();
}

void ColSalas::add(KeyInteger* k, Sala * s) {
    salas->add(k, s);
}

void ColSalas::remove(KeyInteger* k) {
    salas->remove(k);
}

bool ColSalas::member(KeyInteger* k) {
    return salas->member(k);
}

int ColSalas::getSize() const {
    return salas->getSize();
}

Sala* ColSalas::find(KeyInteger* k)
{
	return dynamic_cast<Sala*>(salas->find(k));
}

bool ColSalas::isEmpty() const {
    if (this->getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

SalaIterator ColSalas::getIterator() {
	return SalaIterator(salas->getIterator());
}

ColSalas::~ColSalas() {
    IIterator* it = salas->getIterator();
    while (it->hasCurrent()) {
        Sala* temp = dynamic_cast<Sala*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete salas;
}

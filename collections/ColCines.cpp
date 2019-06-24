#include "ColCines.h"

ColCines::ColCines() {
    cines = new List();
}

void ColCines::add(Cine * c) {
    cines->add(c);
}

void ColCines::remove(Cine* c) {
    cines->remove(c);
}

bool ColCines::member(Cine* c) {
    return cines->member(c);
}

int ColCines::getSize() const {
    return cines->getSize();
}

bool ColCines::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

CineIterator ColCines::getIterator() {
	return CineIterator(cines->getIterator());
}

ColCines::~ColCines() {
    IIterator* it = cines->getIterator();
    while (it->hasCurrent()) {
        Cine* temp = dynamic_cast<Cine*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete cines;
}
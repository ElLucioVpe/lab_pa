#include "ColCines.h"

ColCines::ColCines() {
    cines = new OrderedDictionary();
}

void ColCines::add(KeyInteger* k,Cine * c) {
    cines->add(k,c);
}

void ColCines::remove(KeyInteger*k) {
    cines->remove(k);
}

bool ColCines::member(KeyInteger*k) {
    return cines->member(k);
}

Cine* ColCines::find(KeyInteger* k)
{
	return dynamic_cast<Cine*>(cines->find(k));
}

int ColCines::getSize() const {
    return cines->getSize();
}
Cines* ColCines::find(String* k)
{
	return dynamic_cast<Cines*>(cines->find(k));
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

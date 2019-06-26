#include "ColSalas.h"

ColSalas::ColSalas() {
    salas = new OrderedDictionary();
}

void ColSalas::add(String *k,Sala * c) {
    salas->add(k,c);
}

void ColSalas::remove(String *k) {
    Salas->remove(k);
}

bool ColSalas::member(String *k) {
    return salas->member(k);
}

int ColSalas::getSize() const {
    return salas->getSize();
}
Salas* ColSalas::find(String* k)
{
	return dynamic_cast<Salas*>(salas->find(k));
}

bool ColSalas::isEmpty() const {
    if (this->getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

//SalaIterator ColSala::getIterator() {
//	return SalaIterator(salas->getIterator());
//}

//ColSalas::~ColSalas() {
//    IIterator* it = salas->getIterator();
//    while (it->hasCurrent()) {
//        Sala* temp = dynamic_cast<Salas*>(it->getCurrent());
//        it->next();
//        delete temp;
//    }
//    delete it;
//    delete salas;
//}

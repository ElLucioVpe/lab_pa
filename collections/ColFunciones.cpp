#include "ColFunciones.h"

ColFunciones::ColFunciones() {
    funciones = new List();
}

void ColFunciones::add(Usuario * u) {
    funciones->add(u);
}

void ColFunciones::remove(Usuario * u) {
    funciones->remove(u);
}

bool ColFunciones::member(Usuario * u) {
    return funciones->member(u);
}

int ColFunciones::getSize() const {
    return funciones->getSize();
}

bool ColFunciones::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

IIterator* ColFunciones::getIterator() {
	return funciones->getIterator();
}

ColFunciones::~ColFunciones() {
    IIterator* it = funciones->getIterator();
    while (it->hasCurrent()) {
        Funcion* temp = dynamic_cast<Funcion*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete funciones;
}


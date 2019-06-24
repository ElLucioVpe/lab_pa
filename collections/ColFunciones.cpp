#include "ColFunciones.h"

ColFunciones::ColFunciones() {
    funciones = new List();
}

void ColFunciones::add(Funcion * f) {
    funciones->add(f);
}

void ColFunciones::remove(Funcion * f) {
    funciones->remove(f);
}

bool ColFunciones::member(Funcion * f) {
    return funciones->member(f);
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

FuncionIterator ColFunciones::getIterator() {
	return FuncionIterator(funciones->getIterator());
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


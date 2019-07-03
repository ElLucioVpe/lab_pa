#include "ColFunciones.h"

ColFunciones::ColFunciones() {
    funciones = new OrderedDictionary();
}

void ColFunciones::add(KeyInteger* k, Funcion * f) {
    funciones->add(k, f);
}

void ColFunciones::remove(KeyInteger* k) {
    funciones->remove(k);
}

bool ColFunciones::member(KeyInteger* k) {
    return funciones->member(k);
}

int ColFunciones::getSize() const {
    return funciones->getSize();
}

Funcion* ColFunciones::find(KeyInteger* k)
{
	return dynamic_cast<Funcion*>(funciones->find(k));
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


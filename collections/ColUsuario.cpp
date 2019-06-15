#include "ColUsuario.h"

ColUsuario::ColUsuario() {
    this->usuarios = new List();
}

ColUsuario* ColUsuario::getInstance(){
    if (instance == nullptr)
        instance = new ColUsuario();
    return instance;
}


void ColUsuario::add(Usuario * u) {
    this->usuarios->add(u);
}

void ColUsuario::remove(Usuario * u) {
    this->usuarios->remove(u);
}

bool ColUsuario::member(Usuario * u) {
    return this->usuarios->member(u);
}

int ColUsuario::getSize() const {
    return this->usuarios->getSize();
}

bool ColUsuario::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

ColUsuario::~ColUsuario() {
    IIterator* it = this->usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* temp = dynamic_cast<Usuario*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete usuarios;
    instance = nullptr;
}
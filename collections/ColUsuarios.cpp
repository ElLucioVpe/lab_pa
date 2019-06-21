#include "ColUsuarios.h"

ColUsuarios::ColUsuarios() {
    usuarios = new List();
}

void ColUsuarios::add(Usuario * u) {
    usuarios->add(u);
}

void ColUsuarios::remove(Usuario * u) {
    usuarios->remove(u);
}

bool ColUsuarios::member(Usuario * u) {
    return usuarios->member(u);
}

int ColUsuarios::getSize() const {
    return usuarios->getSize();
}

bool ColUsuarios::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

UsuarioIterator ColUsuarios::getIterator() {
	return UsuarioIterator(usuarios->getIterator());
}

ColUsuarios::~ColUsuarios() {
    IIterator* it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* temp = dynamic_cast<Usuario*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete usuarios;
}

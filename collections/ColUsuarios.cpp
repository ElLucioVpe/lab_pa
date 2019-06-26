#include "ColUsuarios.h"

ColUsuarios::ColUsuarios() {
    usuarios = new OrderedDictionary();
}

void ColUsuarios::add(String* k,Usuario * u) {
    usuarios->add(k, u);
}

void ColUsuarios::remove(String* k) {
    usuarios->remove(k);
}

bool ColUsuarios::member(String * k) {
    return usuarios->member(k);
}

Usuario* ColUsuarios::find(String* k)
{
	return dynamic_cast<Usuario*>(usuarios->find(k));
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

#include "ColUsuario.h"

ColUsuario::ColUsuario() {
    usuarios = new List();
}

/*ColUsuario* ColUsuario::getInstance(){
	if (instance == nullptr){
        instance = new ColUsuario();
	}    
    return instance;
}*/


void ColUsuario::add(Usuario * u) {
    usuarios->add(u);
}

void ColUsuario::remove(Usuario * u) {
    usuarios->remove(u);
}

bool ColUsuario::member(Usuario * u) {
    return usuarios->member(u);
}

int ColUsuario::getSize() const {
    return usuarios->getSize();
}

bool ColUsuario::isEmpty() const {
    if (this->getSize() == 0){ 
        return true;
    }
    else{
        return false;
    }
}

UsuarioIterator ColUsuario::getIterator() {
	return UsuarioIterator(usuarios->getIterator());
}

ColUsuario::~ColUsuario() {
    IIterator* it = usuarios->getIterator();
    while (it->hasCurrent()) {
        Usuario* temp = dynamic_cast<Usuario*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete usuarios;
    //instance = nullptr;
}

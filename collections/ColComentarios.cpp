#include "ColComentarios.h"

ColComentarios::ColComentarios() {
    comentarios = new OrderedDictionary();
}

void ColComentarios::add(KeyString* k,Comentario* c) {
	comentarios->add(k,c);
}

void ColComentarios::remove(KeyString* k) {
    comentarios->remove(k);
}

bool ColComentarios::member(KeyString* k) {
    return comentarios->member(k);
}

Comentario* ColComentarios::find(KeyString* k)
{
	return dynamic_cast<Comentario*>(comentarios->find(k));
}


int ColComentarios::getSize() const {
    return comentarios->getSize();
}

bool ColComentarios::isEmpty() const {
    if (this->getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

ComentarioIterator ColComentarios::getIterator() {
	return ComentarioIterator(comentarios->getIterator());
}

ColComentarios::~ColComentarios() {
    IIterator* it = comentarios->getIterator();
    while (it->hasCurrent()) {
        Comentario* temp = dynamic_cast<Comentario*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete comentarios;
}

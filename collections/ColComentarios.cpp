#include "ColComentarios.h"

ColComentarios::ColComentarios() {
    comentarios = new OrderedDictionary();
}

void ColComentarios::add(KeyInteger* k,Comentario* c) {
	comentarios->add(k,c);
}

void ColComentarios::remove(KeyInteger* k) {
    comentarios->remove(k);
}

bool ColComentarios::member(KeyInteger* k) {
    return comentarios->member(k);
}

Comentario* ColComentarios::find(KeyInteger* k)
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

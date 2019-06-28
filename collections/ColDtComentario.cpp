#include "ColDtComentarios.h"

ColDtComentarios::ColDtComentarios() {
    Dtcomentarios = new OrderedDictionary();
}

void DtColComentarios::add(KeyInteger* k, DtComentario* c) {
	Dtcomentarios->add(k,c);
}

void DtColComentarios::remove(KeyInteger* k) {
    Dtcomentarios->remove(k);
}

bool DtColComentarios::member(KeyInteger* k) {
    return Dtcomentarios->member(k);
}

DtComentario* DtColComentarios::find(KeyInteger* k)
{
	return dynamic_cast<DtComentario*>(Dtcomentarios->find(k));
}


int DtColComentarios::getSize() const {
    return Dtcomentarios->getSize();
}

bool DtColComentarios::isEmpty() const {
    if (this->getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

DtComentarioIterator DtColComentarios::getIterator() {
	return DtComentarioIterator(DtComentarios->getIterator());
}

DtColComentarios::~DtColComentarios() {
    IIterator* it = DtComentarios->getIterator();
    while (it->hasCurrent()) {
        DtComentario* temp = dynamic_cast<DtComentario*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete Dtcomentarios;
}

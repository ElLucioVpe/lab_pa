#include "ColPeliculas.h"

ColPeliculas::ColPeliculas() {
    peliculas = new OrderedDictionary();
}

void ColPeliculas::add(KeyString* k,Pelicula* p) {
	peliculas->add(k,p);
}

void ColPeliculas::remove(KeyString* k) {
    peliculas->remove(k);
}

bool ColPeliculas::member(KeyString* k) {
    return peliculas->member(k);
}

Pelicula* ColPeliculas::find(KeyString* k)
{
	return dynamic_cast<Pelicula*>(peliculas->find(k));
}


int ColPeliculas::getSize() const {
    return peliculas->getSize();
}

bool ColPeliculas::isEmpty() const {
    if (this->getSize() == 0){
        return true;
    }
    else{
        return false;
    }
}

PeliculaIterator ColPeliculas::getIterator() {
	return PeliculaIterator(peliculas->getIterator());
}

ColPeliculas::~ColPeliculas() {
    IIterator* it = peliculas->getIterator();
    while (it->hasCurrent()) {
        Pelicula* temp = dynamic_cast<Pelicula*>(it->getCurrent());
        it->next();
        delete temp;
    }
    delete it;
    delete peliculas;
}

#include "ColPeliculas.h"

ColPeliculas::ColPeliculas() {
    peliculas = new List();
}

void ColPeliculas::add(Pelicula* p) {
	peliculas->add(p);
}

void ColPeliculas::remove(Pelicula* p) {
    peliculas->remove(p);
}

bool ColPeliculas::member(Pelicula* p) {
    return peliculas->member(p);
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


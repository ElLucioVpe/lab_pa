#include "ColPeliculas.h"

ColPeliculas::ColPeliculas() {
    peliculas = new List();
}

void ColPeliculas::add(Usuario * u) {
    peliculas->add(u);
}

void ColPeliculas::remove(Usuario * u) {
    peliculas->remove(u);
}

bool ColPeliculas::member(Usuario * u) {
    return peliculas->member(u);
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

IIterator* ColPeliculas::getIterator() {
	return peliculas->getIterator();
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


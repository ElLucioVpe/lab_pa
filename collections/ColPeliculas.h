#ifndef COLPELICULAS_H
#define	COLPELICULAS_H

#include <iostream>
#include "../interfaces/ICollection.h"
#include "PeliculaIterator.h"
#include "../classes/headers/Pelicula.h"
#include "OrderedDictionary.h"
#include "List.h"

class ColPeliculas {
private:
    IDictionary* peliculas;

public:
    ColPeliculas();
    ~ColPeliculas();

    void add(String * k,Pelicula * p);
    void remove(String * k);
    bool member(String * k);
    Pelicula* find(String* k);
    bool isEmpty() const;
    int getSize() const;
    PeliculaIterator getIterator();
};

#endif	/* COLPELICULAS_H */

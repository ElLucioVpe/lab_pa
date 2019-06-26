#ifndef COLPELICULAS_H
#define	COLPELICULAS_H

#include <iostream>
#include "../interfaces/ICollection.h"
#include "PeliculaIterator.h"
#include "../classes/headers/Pelicula.h"
#include "OrderedDictionary.h"
#include "../KeyString.h"

class ColPeliculas {
private:
    IDictionary* peliculas;

public:
    ColPeliculas();
    ~ColPeliculas();

    void add(KeyString* k,Pelicula * p);
    void remove(KeyString* k);
    bool member(KeyString* k);
    Pelicula* find(KeyString* k);
    bool isEmpty() const;
    int getSize() const;
    PeliculaIterator getIterator();
};

#endif	/* COLPELICULAS_H */

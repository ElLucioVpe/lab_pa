#ifndef COLPELICULAS_H
#define	COLPELICULAS_H

#include <iostream>
#include "../interfaces/ICollection.h"
#include "PeliculaIterator.h"
#include "../classes/headers/Pelicula.h"
#include "List.h"

class ColPeliculas {
private:
    ICollection* peliculas;

public:
    ColPeliculas();
    ~ColPeliculas();

    void add(Pelicula * p);
    void remove(Pelicula * p);
    bool member(Pelicula * p);
    bool isEmpty() const;
    int getSize() const;
    PeliculaIterator getIterator();
};

#endif	/* COLPELICULAS_H */
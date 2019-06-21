#ifndef COLPELICULAS_H
#define	COLPELICULAS_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Pelicula.h"

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
    Iterator* getIterator();
};

#endif	/* COLPELICULAS_H */
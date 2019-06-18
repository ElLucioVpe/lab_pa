#ifndef COLPELICULAS_H
#define	COLPELICULAS_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Pelicula.h"

class ColPeliculas {
    private:
    public:
        ColReservas();
        void add(Pelicula *);
        void remove(Pelicula *);
        bool member(Pelicula *) const;
};

#endif	/* COLPELICULAS_H */
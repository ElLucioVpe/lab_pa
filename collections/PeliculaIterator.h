#ifndef PELICULAITERATOR_H
#define	PELICULAITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Pelicula.h"

class PeliculaIterator {
public:
	PeliculaIterator();
	PeliculaIterator(IIterator* listIt);
	Pelicula* getCurrent();
	bool hasCurrent();
	void next();

	~PeliculaIterator();
private:
	IIterator* it;
};

#endif	/* PELICULAITERATOR_H */
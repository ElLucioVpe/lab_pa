#include "PeliculaIterator.h"
#include <stdexcept>

PeliculaIterator::PeliculaIterator()
{

}

PeliculaIterator::PeliculaIterator(IIterator* listIt) {
	it = listIt;
}

Pelicula* PeliculaIterator::getCurrent()
{
	return dynamic_cast<Pelicula*>(it->getCurrent());
}

bool PeliculaIterator::hasCurrent()
{
	return it->hasCurrent();
}

void PeliculaIterator::next()
{
	it->next();
}

PeliculaIterator::~PeliculaIterator()
{

}

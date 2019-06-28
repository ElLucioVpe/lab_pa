#include "PuntajeIterator.h"
#include <stdexcept>

PuntajeIterator::PuntajeIterator()
{

}

PuntajeIterator::PuntajeIterator(IIterator* listIt) {
	it = listIt;
}

Puntaje* PuntajeIterator::getCurrent()
{
	return dynamic_cast<Puntaje*>(it->getCurrent());
}

bool PuntajeIterator::hasCurrent()
{
	return it->hasCurrent();
}

void PuntajeIterator::next()
{
	it->next();
}

PuntajeIterator::~PuntajeIterator()
{

}

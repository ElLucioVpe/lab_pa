#include "ComentarioIterator.h"
#include <stdexcept>

ComentarioIterator::ComentarioIterator()
{

}

ComentarioIterator::ComentarioIterator(IIterator* listIt) {
	it = listIt;
}

Comentario* ComentarioIterator::getCurrent()
{
	return dynamic_cast<Comentario*>(it->getCurrent());
}

bool ComentarioIterator::hasCurrent()
{
	return it->hasCurrent();
}

void ComentarioIterator::next()
{
	it->next();
}

ComentarioIterator::~ComentarioIterator()
{

}

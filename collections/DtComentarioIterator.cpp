#include "DtComentarioIterator.h"
#include <stdexcept>

DtComentarioIterator::DtComentarioIterator()
{

}

DtComentarioIterator::DtComentarioIterator(IIterator* listIt) {
	it = listIt;
}

Comentario* DtComentarioIterator::getCurrent()
{
	return dynamic_cast<DtComentario*>(it->getCurrent());
}

bool DtComentarioIterator::hasCurrent()
{
	return it->hasCurrent();
}

void DtComentarioIterator::next()
{
	it->next();
}

DtComentarioIterator::~DtComentarioIterator()
{

}

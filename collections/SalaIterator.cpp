#include "SalaIterator.h"
#include <stdexcept>

SalaIterator::SalaIterator()
{

}

SalaIterator::SalaIterator(IIterator* listIt) {
	it = listIt;
}

Sala* SalaIterator::getCurrent()
{
	return dynamic_cast<Sala*>(it->getCurrent());
}

bool SalaIterator::hasCurrent()
{
	return it->hasCurrent();
}

void SalaIterator::next()
{
	it->next();
}

SalaIterator::~SalaIterator()
{

}

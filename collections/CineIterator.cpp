#include "CineIterator.h"
#include <stdexcept>

CineIterator::CineIterator()
{

}

CineIterator::CineIterator(IIterator* listIt) {
	it = listIt;
}

Cine* CineIterator::getCurrent()
{
	return dynamic_cast<Cine*>(it->getCurrent());
}

bool CineIterator::hasCurrent()
{
	return it->hasCurrent();
}

void CineIterator::next()
{
	it->next();
}

CineIterator::~CineIterator()
{

}
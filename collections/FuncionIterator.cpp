#include "FuncionIterator.h"
#include <stdexcept>

FuncionIterator::FuncionIterator()
{

}

FuncionIterator::FuncionIterator(IIterator* listIt) {
	it = listIt;
}

Funcion* FuncionIterator::getCurrent()
{
	return dynamic_cast<Funcion*>(it->getCurrent());
}

bool FuncionIterator::hasCurrent()
{
	return it->hasCurrent();
}

void FuncionIterator::next()
{
	it->next();
}

FuncionIterator::~FuncionIterator()
{

}

#include "ReservaIterator.h"
#include <stdexcept>
using namespace std;

ReservaIterator::ReservaIterator(IIterator * listIt) {
	it = listIt;
}

Reserva *ReservaIterator::getCurrent()
{
	return dynamic_cast<Reserva*>(it->getCurrent());
}

bool ReservaIterator::hasCurrent()
{
    return it->hasCurrent();
}

void ReservaIterator::next()
{
    it->next();
}

ReservaIterator::~UsuarioIterator()
{
   
}

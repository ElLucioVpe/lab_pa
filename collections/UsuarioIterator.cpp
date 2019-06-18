#include "UsuarioIterator.h"
#include <stdexcept>
using namespace std;

UsuarioIterator::UsuarioIterator(IIterator * listIt) {
	it = listIt;
}

Usuario *UsuarioIterator::getCurrent()
{
	return dynamic_cast<Usuario*>(it->getCurrent());
}

bool UsuarioIterator::hasCurrent()
{
    return it->hasCurrent();
}

void UsuarioIterator::next()
{
    it->next();
}

UsuarioIterator::~UsuarioIterator()
{
   
}

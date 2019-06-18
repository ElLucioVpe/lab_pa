#ifndef USUARIOITERATOR_H
#define	USUARIOITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Usuario.h"

class UsuarioIterator {
public:
	UsuarioIterator();
    UsuarioIterator(IIterator * listIt);
    Usuario *getCurrent();
    bool hasCurrent();
    void next();
    
    ~UsuarioIterator();
private:
    IIterator *it;
};

#endif	/* USUARIOITERATOR_H */


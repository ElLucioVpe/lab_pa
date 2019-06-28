#ifndef DTCOMENTARIOITERATOR_H
#define	DTCOMENTARIOITERATOR_H

#include "ListIterator.h"
#include "../datatypes/headers/DtComentario.h"

class DtComentarioIterator {
public:
	DtComentarioIterator();
	DtComentarioIterator(IIterator* listIt);
	Funcion* getCurrent();
	bool hasCurrent();
	void next();

	~DtComentarioIterator();
private:
	IIterator* it;
};

#endif	/* DTCOMENTARIOITERATOR_H */

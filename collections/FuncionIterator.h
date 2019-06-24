#ifndef FUNCIONITERATOR_H
#define	FUNCIONITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Funcion.h"

class FuncionIterator {
public:
	FuncionIterator();
	FuncionIterator(IIterator* listIt);
	Funcion* getCurrent();
	bool hasCurrent();
	void next();

	~FuncionIterator();
private:
	IIterator* it;
};

#endif	/* FUNCIONITERATOR_H */
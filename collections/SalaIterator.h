#ifndef SALAITERATOR_H
#define	SALAITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Sala.h"

class SalaIterator {
public:
	SalaIterator();
	SalaIterator(IIterator* listIt);
	Sala* getCurrent();
	bool hasCurrent();
	void next();

	~SalaIterator();
private:
	IIterator* it;
};

#endif	/* SALAITERATOR_H */

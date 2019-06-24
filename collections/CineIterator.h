#ifndef CINEITERATOR_H
#define	CINEITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Cine.h"

class CineIterator {
public:
	CineIterator();
	CineIterator(IIterator* listIt);
	Cine* getCurrent();
	bool hasCurrent();
	void next();

	~CineIterator();
private:
	IIterator* it;
};

#endif	/* CINEITERATOR_H */
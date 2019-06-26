#ifndef COLCINES_H
#define	COLCINES_H

#include "../interfaces/ICollection.h"
#include "CineIterator.h"
#include "../classes/headers/Cine.h"
#include "OrderedDictionary.h"
#include "../KeyInteger.h"

class ColCines {
private:
    IDictionary* cines;

public:
    ColCines();
    ~ColCines();

    void add(KeyInteger*k, Cine * c);
    void remove(KeyInteger*k);
    bool member(KeyInteger*k);
	Cine* find(KeyInteger* k);
    bool isEmpty() const;
    int getSize() const;
    CineIterator getIterator();
};

#endif	/* COLCINES_H */

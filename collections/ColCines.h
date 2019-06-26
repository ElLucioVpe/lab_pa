#ifndef COLCINES_H
#define	COLCINES_H

#include "../interfaces/ICollection.h"
#include "CineIterator.h"
#include "../classes/headers/Cine.h"
#include "OrderedDictionary.h"
#include "List.h"

class ColCines {
private:
    IDictionary* cines;

public:
    ColCines();
    ~ColCines();

    void add(String *k, Cine * c);
    void remove(String *k);
    bool member(String *k);
    bool isEmpty() const;
    int getSize() const;
    CineIterator getIterator();
};

#endif	/* COLCINES_H */

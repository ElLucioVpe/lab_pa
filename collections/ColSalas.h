#ifndef COLSALAS_H
#define	COLSALAS_H

#include "../interfaces/ICollection.h"
#include "SalaIterator.h"
#include "../classes/headers/Sala.h"
#include "OrderedDictionary.h"
#include "../KeyInteger.h"

class ColSalas {
private:
    IDictionary* salas;

public:
    ColSalas();
    ~ColSalas();

    void add(KeyInteger* k, Sala * c);
    void remove(KeyInteger* k);
    bool member(KeyInteger*k);
    Sala* find(KeyInteger*k);
    bool isEmpty() const;
    int getSize() const;
    SalaIterator getIterator();
};

#endif	/* COLSALAS_H */

#ifndef COLSALAS_H
#define	COLSALAS_H

#include "../interfaces/ICollection.h"
//#include "SalaIterator.h"
#include "../classes/headers/Sala.h"
#include "OrderedDictionary.h"
#include "List.h"

class ColSalas {
private:
    IDictionary* salas;

public:
    ColSalas();
    ~ColSalas();

    void add(String *k, Sala * c);
    void remove(String *k);
    bool member(String *k);
    Cines * find(String *k);
    bool isEmpty() const;
    int getSize() const;
    //SalaIterator getIterator();
};

#endif	/* COLSALAS_H */

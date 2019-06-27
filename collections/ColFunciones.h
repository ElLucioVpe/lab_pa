#ifndef COLFUNCIONES_H
#define	COLFUNCIONES_H

#include "../interfaces/ICollection.h"
#include "FuncionIterator.h"
#include "../classes/headers/Funcion.h"
#include "OrderedDictionary.h"
#include "../KeyInteger.h"

class ColFunciones {
private:
    IDictionary* funciones;

public:
    ColFunciones();
    ~ColFunciones();

    void add(KeyInteger* k, Funcion * f);
    void remove(KeyInteger* k);
    bool member(KeyInteger* k);
	Funcion* find(KeyInteger* k);
    bool isEmpty() const;
    int getSize() const;
    FuncionIterator getIterator();
};

#endif	/* COLFUNCIONES_H */
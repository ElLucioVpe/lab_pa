#ifndef COLFUNCIONES_H
#define	COLFUNCIONES_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Funcion.h"

class ColFunciones {
private:
    ICollection* funciones;

public:
    ColFunciones();
    ~ColFunciones();

    void add(Funcion * f);
    void remove(Funcion * f);
    bool member(Funcion * f);
    bool isEmpty() const;
    int getSize() const;
    Iterator* getIterator();
};

#endif	/* COLFUNCIONES_H */
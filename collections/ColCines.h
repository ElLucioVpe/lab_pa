#ifndef COLCINES_H
#define	COLCINES_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Cine.h"

class ColCines {
private:
    ICollection* cines;

public:
    ColCines();
    ~ColCines();

    void add(Cine * c);
    void remove(Cine * c);
    bool member(Cine * c);
    bool isEmpty() const;
    int getSize() const;
    Iterator* getIterator();
};

#endif	/* COLCINES_H */
#ifndef COLFUNCIONES_H
#define	COLFUNCIONES_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Funcion.h"

class ColFunciones {
    private:
    public:
        ColFunciones();
        void add(funcion *);
        void remove(funcion *);
        bool member(funcion *) const;
};

#endif	/* COLFUNCIONES_H */
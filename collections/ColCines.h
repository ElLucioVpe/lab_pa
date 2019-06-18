#ifndef COLCINES_H
#define	COLCINES_H

#include "../interfaces/ICollection.h"
#include "../classes/headers/Cine.h"

class ColCines {
    private:
    public:
        ColCines();
        void add(Cine *);
        void remove(Cine *);
        bool member(Cine *) const;
};

#endif	/* COLCINES_H */
#ifndef DTCINE_H
#define DTCINE_H

#include "../../classes/headers/Cine.h"

class DtCine {
public:
    DtCine();
    DtCine(int, string);

    int getIdCine() const;
    string getDireccion() const;

    virtual ~DtCine();

private:
    int idCine;
    string direccion;

};

#endif	/* DTCINE_H */
    

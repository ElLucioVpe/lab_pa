#ifndef DTCINE_H
#define DTCINE_H

#include "../../classes/headers/Cine.h"

class DtCine : public ICollectible {
public:
    DtCine();
    DtCine(int, string);

    int getIdCine() const;
    string getDireccion() const;
	bool operator<(const DtCine& c) const;
    virtual ~DtCine();

private:
    int idCine;
    string direccion;

};

#endif	/* DTCINE_H */
    

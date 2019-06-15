#ifndef DTCINE_H
#define DTCINE_H

#include "../headers/Cine.h"

Class DtCine {
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


    

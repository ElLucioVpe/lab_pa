#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "../headers/Funcion.h"

Class DtFuncion {
public:
    DtFuncion();
    DtFuncion(int, date);

    int getIdFuncion() const;
    string getHorario() const;

    virtual ~DtFuncion();

private:
    int idFuncion;
    date horario;
    };

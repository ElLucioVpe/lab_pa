#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "../../classes/headers/Funcion.h"

class DtFuncion {
public:
    DtFuncion();
    DtFuncion(int, string);

    int getIdFuncion() const;
    string getHorario() const;

    virtual ~DtFuncion();

private:
    int idFuncion;
	string horario;
};

#endif	/* DTFUNCION_H */
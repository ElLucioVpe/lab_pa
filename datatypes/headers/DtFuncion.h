#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "../../classes/headers/Funcion.h"

class DtFuncion : public ICollectible {
public:
    DtFuncion();
    DtFuncion(int, string);

    int getIdFuncion() const;
    string getHorario() const;
	bool operator< (const DtFuncion& f) const;

    virtual ~DtFuncion();

private:
    int idFuncion;
	string horario;
};

#endif	/* DTFUNCION_H */
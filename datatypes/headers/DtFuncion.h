#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "../../classes/headers/Funcion.h"

class DtFuncion : public ICollectible {
public:
    DtFuncion();
    DtFuncion(int, time_t);

    int getIdFuncion() const;
    time_t getHorario() const;
	bool operator< (const DtFuncion& f) const;

    virtual ~DtFuncion();

private:
    int idFuncion;
	time_t horario;
};

#endif	/* DTFUNCION_H */
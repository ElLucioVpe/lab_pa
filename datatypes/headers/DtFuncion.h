#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "../../classes/headers/Funcion.h"

class DtFuncion : public ICollectible {
public:
    DtFuncion();
    DtFuncion(int, time_t, int);

    int getIdFuncion() const;
    time_t getHorario() const;
	int getIdSala();
	bool operator< (const DtFuncion& f) const;

    virtual ~DtFuncion();

private:
    int idFuncion;
	time_t horario;
	int idSala;
};

#endif	/* DTFUNCION_H */
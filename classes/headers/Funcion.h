#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include <string>
#include <ctime>
#include "../../interfaces/ICollectible.h"
#include "Cine.h"
#include "../../collections/ColReservas.h"

using namespace std;

class Funcion : public ICollectible {
public:
    Funcion(int idFuncion, string horario);
	int getIdFuncion();
	time_t getHorario();
	Cine* getCines();
	void setIdfuncion(int IdFuncion);
	void setHorario(string h);
	void EliminarReservas();
	bool EsDeCine(int IdCine);
	void ReservarFuncion(int, float, string, string, string);
	~Funcion();

private: 
	int IdFuncion;
	time_t Horario;
	Cine* _cine;
	ColReservas reservas;
};

#endif /* FUNCION_H */

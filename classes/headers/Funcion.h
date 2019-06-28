#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include <string>
#include <ctime>
#include "../../interfaces/ICollectible.h"
#include "Cine.h"
#include "Sala.h"
#include "../../collections/ColReservas.h"

using namespace std;

class Funcion : public ICollectible {
public:
    Funcion(int IdFuncion, string _horario, Cine* _cine, Sala* _sala);
	int getIdFuncion();
	time_t getHorario();
	Cine* getCines();
	Sala* getSala();
	void setIdfuncion(int IdFuncion);
	void setHorario(time_t h);
	void EliminarReservas();
	bool EsDeCine(int IdCine);
	void ReservarFuncion(int, float, string, string, string);
	~Funcion();

private: 
	int IdFuncion;
	time_t Horario;
	Cine* _cine;
	Sala* _sala;
	ColReservas* reservas;
};

#endif /* FUNCION_H */

#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include <string>
#include <ctime>
#include "../../interfaces/ICollectible.h"
#include "Cine.h"
#include "Sala.h"
#include "../../collections/ColReservas.h"
#include "../../datatypes/headers/DtTarjetaDeCredito.h"
#include "../../datatypes/headers/DtTarjetaDeDebito.h"

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
	void ReservarFuncion(int, float, Usuario* , string, string, float);
	int AsientosReservados();
	ICollection* ListarReservas(string user);
	~Funcion();

private: 
	int IdFuncion;
	time_t Horario;
	Cine* _cine;
	Sala* _sala;
	ColReservas* reservas;
};

#endif /* FUNCION_H */

#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "Cine.h"
#include "../../collections/ColReservas.h"

using namespace std;

class Funcion : public ICollectible {
public:
    Funcion(int idFuncion, string Horario);
	int getIdFuncion();
	string getHorario();
	Cine* getCines();
	//Dtfuncion getDatafuncion();
	void setIdfuncion(int IdFuncion);
	void setHorario(string h);
	void EliminarReservas();
	bool EsDePelicula(string t);
	void ReservarFuncion(int, float, string);
	~Funcion();
	
private: 
	int IdFuncion;
	string Horario;
	Cine* _cine;
	ColReservas reservas;
};

#endif /* FUNCION_H */

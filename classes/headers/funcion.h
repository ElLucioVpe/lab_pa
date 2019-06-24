#ifndef FUNCION_H
#define FUNCION_H
#include "Cine.h"
#include "Pelicula.h"
#include "../../collections/ColReservas.h"

class Funcion : public ICollectible{
public:
    Funcion(int, string);
	int getIdFuncion();
	string getHorario();
	Cine* getCines();
	//Dtfuncion getDatafuncion();
	void setIdfuncion( int IdFuncion);
	void setHorario(string);
	void EliminarReservas();
	bool EsDePelicula(string);
	void ReservarFuncion(int, float, string);
	~Funcion();
	
private: 
	int IdFuncion;
	string Horario;
	Cine* cine;
	Pelicula* pelicula;
	ColReservas reservas;
};

#endif /* FUNCION_H */
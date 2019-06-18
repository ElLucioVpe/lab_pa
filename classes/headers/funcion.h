#ifndef FUNCION_H
#define FUNCION_H
#include "../headers/Cine.h"

class Funcion {
public:
    Funcion( int, date);
	int getIdFuncion();
	date getHorario();
	//Dtfuncion getDatafuncion();
	void setIdfuncion( int IdFuncion);
	void setHorario( date );
	void ElimiarReservas();
	bool EsDePelicula(string);
	void ReservarFuncion(int,float,int,string);
	void getCines();
private: 
	int IdFuncion;
	date Horario;
	Cine* cine;
	
};

#endif /* CINE_H */
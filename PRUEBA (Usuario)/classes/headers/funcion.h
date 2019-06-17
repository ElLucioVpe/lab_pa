#ifndef FUNCION_H
#define FUNCION_H
#include "../headers/cine.h"

class funcion {
public:
	funcion( int, date);
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
	cine* cine;
	
};

#endif /* CINE_H */

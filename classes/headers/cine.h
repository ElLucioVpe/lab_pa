#ifndef CINE_H
#define CINE_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColFunciones.h"
using namespace std;

class Cine : public ICollectible {
public:
	Cine(int, string);
	int getIdCine();
	string getDireccion();
	ColFunciones getFunciones();
	int getcantFunciones();
	//DtCine getDatacine();
	void setIdCine( int idCine );
	void setDireccion(string Direccion);
	~Cine();

private: 
	string Direccion;
	int IdCine;
	ColFunciones Funciones;
	int cantFunciones;
};

#endif /* CINE_H */


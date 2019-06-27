#ifndef CINE_H
#define CINE_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColSalas.h"
#include "../../datatypes/headers/DtSala.h"
#include <string>

using namespace std;

class Cine : public ICollectible {
public:
	Cine(int, string);
	int getIdCine();
	string getDireccion();
	//DtCine getDatacine();
	void setIdCine(int idCine);
	void setDireccion(string Direccion);
	ICollection* ListarSalas();
	~Cine();

private:
	string Direccion;
	int IdCine;
	ColSalas salas;
};

#endif /* CINE_H */
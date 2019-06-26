#ifndef CINE_H
#define CINE_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include <string>

using namespace std;

class Cine : public ICollectible {
public:
	Cine(int, String);
	int getIdCine();
	string getDireccion();
	//DtCine getDatacine();
	void setIdCine(int idCine);
	void setDireccion(String Direccion);
	~Cine();

private:
	String Direccion;
	int IdCine;
};

#endif /* CINE_H */

#ifndef CINE_H
#define CINE_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
using namespace std;

class Cine : public ICollectible {
public:
	Cine(int, string);
	int getIdCine();
	string getDireccion();
	//DtCine getDatacine();
	void setIdCine( int idCine );
	void setDireccion(string Direccion);
	~Cine();

private: 
	string Direccion;
	int IdCine;
};

#endif /* CINE_H */


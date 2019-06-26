#ifndef SALA_H
#define SALA_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
using namespace std;

class Sala : public ICollectible {
public:
	Sala(int, int);
	int getIdSala();
	int getCantAsientos();
	//DtCine getDatacine();
	void setIdSala( int idCine );
	void setCantAsientos(string Direccion);
	~Sala();

private:
	int CantAsientos;
	int IdSala;
};

#endif /* CINE_H */

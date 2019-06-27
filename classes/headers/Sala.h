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
	void setIdSala( int idCine );
	void setCantAsientos(int cant);
	~Sala();

private:
	int IdSala;
	int CantAsientos;
};

#endif /* SALA_H */

#ifndef DTSALA_H
#define DTSALA_H

#include "../../classes/headers/Cine.h"

class DtSala : public ICollectible {
public:
 	DtSala(int, int);
	int getIdSala();
	int getCantAsientos();
	//DtCine getDatacine();
	void setIdSala( int idCine );
	void setCantAsientos(string Direccion);
	~DtSala();

private:
    int idCine;
    string direccion;

};

#endif	/* DTSALA */
    

#ifndef DTSALA_H
#define DTSALA_H

#include "../../classes/headers/Sala.h"

class DtSala : public ICollectible {
public:
 	DtSala(int, int);
	int getIdSala();
	int getCantAsientos();
	void setIdSala(int id);
	void setCantAsientos(int cantAsientos);
	~DtSala();

private:
    int IdSala;
    int cantAsientos;

};

#endif	/* DTSALA */
    

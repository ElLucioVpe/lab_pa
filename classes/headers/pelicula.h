#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <set>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColFunciones.h"
#include "../../datatypes/headers/DtFuncion.h"
#include "../../datatypes/headers/DtCine.h"
using namespace std;

class Pelicula : public ICollectible {
public:
	Pelicula(string titulo, string poster, string sinopsis, float puntaje);

	string getTitulo();
	string getPoster();
	string getSinopsis();
	float getPuntaje();
	void setTitulo(string titulo);
	void setPoster(string poster);
	void setSinopsis(string sinopsis);
	void setPuntaje(float puntaje);

	void EliminarFunciones();
	//set<DtFuncion> ListarFunciones();
	set<DtCine> getCines();
	~Pelicula();

private:
	string titulo;
	string poster;
	string sinopsis;
	float puntaje;
	ColFunciones funciones;
};

#endif	/* PELICULA_H */
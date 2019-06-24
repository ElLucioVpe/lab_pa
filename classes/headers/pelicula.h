#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
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

private:
	string titulo;
	string poster;
	string sinopsis;
	float puntaje;
};

#endif	/* PELICULA_H */
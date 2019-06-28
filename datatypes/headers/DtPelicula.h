#ifndef DTPELICULA_H
#define DTPELICULA_H

#include <iostream>
using namespace std;

class DtPelicula {
public:
    DtPelicula();
    DtPelicula(string, string, string, float);
    string getTitulo();
    string getPoster();
    string getSinopsis();
    float getPuntaje();
	virtual ~DtPelicula();
private:
  string titulo;
  string poster;
  string sinopsis;
  float puntaje;
};

#endif /* DTPELICULA_H */
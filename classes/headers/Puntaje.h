#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "Usuario.h"
//#include "Pelicula.h"

class Pelicula;

using namespace std;
class Puntaje : public ICollectible {
public:
	Puntaje(int, Usuario*);

	int getValor();
	void setValor( int Valor );
	~Puntaje();

  private:
  Usuario * _usuario;
  int Valor;
  };

  #endif /* PUNTAJE_H */

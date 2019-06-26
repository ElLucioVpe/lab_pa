#ifndef FUNCION_H
#define FUNCION_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColReservas.h"

using namespace std;

class Comentario : public ICollectible {
public:
  Comentario(String Texto);
  String getComentario();
  Void setComentario(string t);
  ~Comentario();
private:
  String Texto;
};

#endif /* FUNCION_H */

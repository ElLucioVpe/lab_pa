#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>

class Pelicula {
  public:
      string getTitulo();
      string getPoster();
      string getSinopsis();
      float getPuntaje();
      void setTitulo(string titulo);
      void setPoster(string poster);
      void setSinopsis(string sinopsis);
      void setPuntaje(string puntaje);

  private:
      string titulo;
      string poster;
      string sinopsis;
      float puntaje;
}

#endif	/* PELICULA_H */
#ifndef PELICULA_H
#define PELICULA_H

class DtPelicula {
public:
    void DtPelicula();
    void DtPelicula(string , string , string , string );
    string DtgetTitulo();
    string DtgetPoster();
    string DtgetSinopsis();
    float DtgetPuntaje();
    virtual ~DtPelicula();

private:
  string titulo;
  string poster;
  string sinopsis;
  float puntaje;

}

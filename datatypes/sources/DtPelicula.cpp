#include "../headers/DtPelicula.h"
#include <cstdlib>

DtPelicula::DtPelicula(){

}
DtPelicula::DtPelicula(string titulo, string poster, string sinopsis, string puntaje){
  this->titulo=titulo;
  this->poster=poster;
  this->sinopsis=sinopsis;
  this->puntaje=puntaje;

}
string DtPelicula::getTitulo(){
    return this->titulo;
}
string DtPelicula::getPoster(){
    return this->poster;
}
string DtPelicula::getSinopsis(){
    return this->sinopsis;
}
string DtPelicula::getPuntaje(){
    return this->puntaje;
}

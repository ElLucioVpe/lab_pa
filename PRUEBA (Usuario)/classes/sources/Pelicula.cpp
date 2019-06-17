#include "../headers/Pelicula.h"
#include <cstdlib>
Pelicula::Pelicula(string titulo, string poster, string sinopsis, string puntaje){
  this->titulo=titulo;
  this->poster=poster;
  this->sinopsis=sinopsis;
  this->puntaje=puntaje;

}
string Pelicula::getTitulo(){
    return this->titulo;
}
string Pelicula::getPoster(){
    return this->poster;
}
string Pelicula::getSinopsis(){
    return this->sinopsis;
}
string Pelicula::getPuntaje(){
    return this->Puntaje;
}
void Pelicula::setTitulo(string titulo){
this->titulo=titulo;
}
void Pelicula::setPoster(string Poster){
this->poster=poster;


void Pelicula::setSinopsis(string sinopsis){
this->sinopsis=sinopsis;
}
void Pelicula::setPuntaje(float puntaje){
this->puntaje=puntaje;

}

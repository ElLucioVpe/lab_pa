#include "../headers/Sistema.h"

Sistema::Sistema() {
    usuarios();
    peliculas();
    cines();
}

bool Sistema::iniciarSesion(string user, string pass) {

}

void CrearReserva(int cantAsientos, float costo, int idSala, Usuario u) {

}

set<string> ListarTitulos() {

}

DtPelicula SeleccionarPelicula(string titulo) {

}

void EliminarPelicula(string titulo) {

}

void VerInfoPelicula(string titulo) {

}

set<string> ListarCines() {

}

set<DtCine> ListarCinesPorTitulo(string tituloPelicula) {

}

set<DtFuncion> ListarFunciones(int idCine, string tituloPelicula) {

}

Sistema::~Sistema() {
    usuarios.~ColUsuarios();
    peliculas.~ColPeliculas();
    cines.~ColCines();
}
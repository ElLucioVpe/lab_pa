#include "../headers/Sistema.h"

Sistema::Sistema() {
    usuarios();
    peliculas();
    cines();
}

bool Sistema::iniciarSesion(string user, string pass) {
    UsuarioIterator it = usuarios.getIterator();
    Usuario* u;
    while (it.hasCurrent()) {
        u = it.getCurrent();
        if (user = u->getNickName()){
            if (u->contraCorrecta(pass)){
                return true;
            } else {
                return false;
            }
        }
        it.next();
    }
    return false;
}

void Sistema::CrearReserva(int cantAsientos, float costo, int idFuncion, Usuario u) {
    //buscar por el cine de dicha funcion
    //cine.funciones.member(f)
    //y añadir la reserva a la coleccion de reservas en dicha funcion
}

set<string> Sistema::ListarTitulos() {
    //set<string> titulos;
    IIterator* it = peliculas->getIterator();
    Pelicula* p;
    while (it->hasCurrent()) {
        p = dynamic_cast<Pelicula*>(it->getCurrent())
        //titulos.insert(p->getTitulo());
        it->next();
    }
}

DtPelicula Sistema::SeleccionarPelicula(string titulo) {

}

void Sistema::EliminarPelicula(string titulo) {

}

void Sistema::VerInfoPelicula(string titulo) {

}

set<string> Sistema::ListarCines() {
    //set<string> ids;
    IIterator* it = cines.getIterator();
    Cine* c;
    while (it->hasCurrent()) {
        c = dynamic_cast<Cine*>(it->getCurrent())
        //ids.insert(c->getTitulo());
        it->next();
    }
}

set<DtCine> Sistema::ListarCinesPorTitulo(string tituloPelicula) {
    //buscar los cines que tengan funciones de la pelicula
}

set<DtFuncion> Sistema::ListarFunciones(int idCine, string tituloPelicula) {
    
}

Sistema::~Sistema() {
    usuarios.~ColUsuarios();
    peliculas.~ColPeliculas();
    cines.~ColCines();
}
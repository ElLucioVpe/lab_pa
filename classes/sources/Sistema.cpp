#include "../headers/Sistema.h"
#include <stdexcept>

Sistema* Sistema::instance = NULL;

Sistema::Sistema() {
    usuarios = new ColUsuarios();
    peliculas = new ColPeliculas();
    cines = new ColCines();
}

Sistema* Sistema::getInstance()
{
	if (instance == NULL)
		instance = new Sistema();
	
	return instance;
}

bool Sistema::iniciarSesion(string user, string pass) {
    UsuarioIterator it = usuarios->getIterator();
    Usuario* u = NULL;
    while (it.hasCurrent()) {
        u = it.getCurrent();
        if (user == u->getNickName()){
            if (u->contraCorrecta(pass)){
                return true;
            } else {
				throw std::invalid_argument("Contrasenia incorrecta");
                return false;
            }
        }
        it.next();
    }
	throw std::invalid_argument("No existe dicho usuario");
    return false;
}

void Sistema::CrearReserva(int cantAsientos, float costo, int idFuncion, Usuario u) {
    //buscar por el cine de dicha funcion
    //cine.funciones.member(f)
    //y añadir la reserva a la coleccion de reservas en dicha funcion
}

set<string> Sistema::ListarTitulos() {
	set<string> titulos;
    PeliculaIterator it = peliculas->getIterator();
    
	Pelicula* p = NULL;
    while (it.hasCurrent()) {
		p = it.getCurrent();
		titulos.insert(p->getTitulo());
        it.next();
    }

	return titulos;
}

DtPelicula Sistema::SeleccionarPelicula(string titulo) {
	//peliculas.find(titulo)
	return DtPelicula();
}

void Sistema::EliminarPelicula(string titulo) {

}

void Sistema::VerInfoPelicula(string titulo) {

}

set<int> Sistema::ListarCines() {
	set<int> ids;
    CineIterator it = cines->getIterator();
    Cine* c = NULL;
    while (it.hasCurrent()) {
		c = it.getCurrent();
        ids.insert(c->getIdCine());
        it.next();
    }

	return ids;
}

ICollection* Sistema::ListarCinesPorTitulo(string tituloPelicula) {
	ICollection* cines;
	//buscar los cines que tengan funciones de la pelicula
	return cines;
}

ICollection* Sistema::ListarFunciones(int idCine, string tituloPelicula) {
	ICollection* funciones;
	//buscar los cines que tengan funciones de la pelicula
	return funciones;
}

Sistema::~Sistema() {
    usuarios->~ColUsuarios();
	delete usuarios;
    peliculas->~ColPeliculas();
	delete peliculas;
    cines->~ColCines();
	delete cines;
}
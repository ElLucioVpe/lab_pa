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

void Sistema::AltaUsuario(string nick, string img, string contra)
{
	KeyString* k = new KeyString(nick);
	Usuario* u = new Usuario(nick, img, contra);
	usuarios->add(k, u);
}

void Sistema::AltaPelicula(string titulo, string poster, string sinopsis)
{
	KeyString* k = new KeyString(titulo);
	Pelicula* p = new Pelicula(titulo, poster, sinopsis, NULL);
	peliculas->add(k, p);
}

void Sistema::AltaCine(int id, string dir)
{
	KeyInteger* k = new KeyInteger(id);
	Cine* c = new Cine(id, dir);
	cines->add(k, c);
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

ICollection* Sistema::ListarTitulos() {
	ICollection* titulos = NULL;
    PeliculaIterator it = peliculas->getIterator();
    
	Pelicula* p = NULL;
    while (it.hasCurrent()) {
		p = it.getCurrent();
		titulos->add(new KeyString(p->getTitulo()));
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

ICollection* Sistema::ListarCines() {
	ICollection* ids = NULL;
    CineIterator it = cines->getIterator();
    Cine* c = NULL;
    while (it.hasCurrent()) {
		c = it.getCurrent();
        ids->add(new KeyInteger(c->getIdCine()));
        it.next();
    }

	return ids;
}

ICollection* Sistema::ListarCinesPorTitulo(string tituloPelicula) {
	ICollection* dts = NULL;
	//buscar los cines que tengan funciones de la pelicula
	return dts;
}

ICollection* Sistema::ListarFunciones(int idCine, string tituloPelicula) {
	ICollection* dts = NULL;
	//buscar los cines que tengan funciones de la pelicula
	return dts;
}

Sistema::~Sistema() {
    usuarios->~ColUsuarios();
	delete usuarios;
    peliculas->~ColPeliculas();
	delete peliculas;
    cines->~ColCines();
	delete cines;
}

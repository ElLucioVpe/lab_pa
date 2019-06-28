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

void Sistema::AltaUsuario(string nick, string img, string contra, bool admin)
{
	KeyString* k = new KeyString(nick);
	Usuario* u = new Usuario(nick, img, contra, admin);
	usuarios->add(k, u);
}

void Sistema::AltaPelicula(string titulo, string poster, string sinopsis)
{
	KeyString* k = new KeyString(titulo);
	Pelicula* p = new Pelicula(titulo, poster, sinopsis, NULL);
	peliculas->add(k, p);
}

void Sistema::AltaCine(string dir)
{
	int id = cines->getSize() + 1;
	KeyInteger* k = new KeyInteger(id);
	Cine* c = new Cine(id, dir);
	cines->add(k, c);
}

void Sistema::AltaSala(int idCine, int cantAsientos)
{
	cines->find(new KeyInteger(idCine))->AltaSala(cantAsientos);
}

DtUsuario* Sistema::iniciarSesion(string user, string pass) {
	Usuario* u = usuarios->find(new KeyString(user));

	if (u == NULL) throw std::invalid_argument("No existe dicho usuario");
	if (u->contraCorrecta(pass) == false) throw std::invalid_argument("Constrasenia incorrecta");

    return new DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin());
}

void Sistema::AltaFuncion(string titulo, string horario, int idCine, int idSala) {
	Pelicula* p = peliculas->find(new KeyString(titulo));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");

	//p->AltaFuncion();
}

void Sistema::AltaComentario(string texto, string pelicula, string autor)
{
	Pelicula* p = peliculas->find(new KeyString(pelicula));
	Usuario* u = usuarios->find(new KeyString(autor));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");
	if (u == NULL) throw std::invalid_argument("El usuario no existe");

	p->agregarComentario(texto, u);
}

ICollection* Sistema::ListarSalas(int idCine) {
	Cine* c = cines->find(new KeyInteger(idCine));

	if (c == NULL) throw std::invalid_argument("El cine no existe");

	return c->ListarSalas();
}

void Sistema::CrearReserva(int cantAsientos, float costo, string titulo, int idFuncion, string usuario, string banco, string financiera) {
	Pelicula* p = peliculas->find(new KeyString(titulo));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");
	
	p->CrearReserva(cantAsientos, costo, idFuncion, usuario, banco, financiera);
}

ICollection* Sistema::ListarTitulos() {
	ICollection* titulos = new List();
    PeliculaIterator it = peliculas->getIterator();
    
	Pelicula* p = NULL;
    while (it.hasCurrent()) {
		p = it.getCurrent();
		titulos->add(new KeyString(p->getTitulo()));
        it.next();
    }

	return titulos;
}

DtPelicula* Sistema::SeleccionarPelicula(string titulo) {
	Pelicula* p = peliculas->find(new KeyString(titulo));
	
	if (p == NULL) throw std::invalid_argument("La pelicula no existe");

	return new DtPelicula(p->getTitulo(), p->getPoster(), p->getSinopsis(), p->getPuntaje());
}
void Sistema::ListarComentariosypuntajes(string titulo){


Pelicula* p = peliculas->find(new  KeyString(titulo));
cout << "\n\tComentarios de: " + p->getTitulo() << endl << endl;
cout << "Su puntaje es: " + p->getPuntaje()<< endl;

return p->ListarComentarios();

}
void Sistema::EliminarPelicula(string titulo) {
	Pelicula* p = peliculas->find(new KeyString(titulo));
	peliculas->remove(new KeyString(p->getTitulo())); //Remuevo la pelicula de la coleccion
	delete p; //Elimina sus funciones las cuales eliminan sus reservas, ademas de los comentarios y puntajes
}


void Sistema::VerInfoPelicula(string titulo) {
	Pelicula* p = peliculas->find(new KeyString(titulo));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");

	cout << "\n\tInformacion sobre " + p->getTitulo() << endl << endl;
	cout << "Poster: \n" + p->getPoster() << endl;
	cout << "Sinopsis: \n" + p->getSinopsis() << endl;
	cout << "Puntaje: " << p->getPuntaje() << endl;
}

ICollection* Sistema::ListarCines() {
	ICollection* ids = new List();
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
	Pelicula* p = peliculas->find(new KeyString(tituloPelicula));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");

	return p->getCines();
}

ICollection* Sistema::ListarFunciones(int idCine, string tituloPelicula) {
	Pelicula* p = peliculas->find(new KeyString(tituloPelicula));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");

	return p->ListarFunciones(idCine);
}

Sistema::~Sistema() {
    usuarios->~ColUsuarios();
	delete usuarios;
    peliculas->~ColPeliculas();
	delete peliculas;
    cines->~ColCines();
	delete cines;
}

int Sistema::DarUltimoCine()
{
	CineIterator it = cines->getIterator();
	Cine* current = NULL;
	Cine* previous = NULL;

	while (it.hasCurrent()) {
		current = it.getCurrent();
		previous = current;
		it.next();
	}
	return previous->getIdCine();
}
Usuario * Sistema::ListarUsuario(DtUsuario * user){
     Usuario * User = usuarios->find(new KeyString(user->getNickName()));
    return User;

}
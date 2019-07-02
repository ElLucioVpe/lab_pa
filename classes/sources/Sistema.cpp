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
	Pelicula* p = new Pelicula(titulo, poster, sinopsis, 0);
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
	

	Cine* c = cines->find(new KeyInteger(idCine));

	if (c == NULL) throw std::invalid_argument("El cine no existe");


	Sala* s = c->GetUnaSala(idSala);

	if (s == NULL) throw std::invalid_argument("La sala no existe");

	p->AltaFuncion(horario,c,s);
}
void Sistema::AltaPuntaje(int puntuacion, string pelicula, string usuario) {
    Pelicula* p = peliculas->find(new KeyString(pelicula));
    Usuario* u = usuarios->find(new KeyString(usuario));

    if (p == NULL) throw std::invalid_argument("La pelicula no existe");
    if (u == NULL) throw std::invalid_argument("El usuario no existe");

    p->puntuarPelicula(puntuacion, u);
}
void Sistema::AltaComentario(vector<int> padres, string texto, string pelicula, string autor)
{
	Pelicula* p = peliculas->find(new KeyString(pelicula));
	Usuario* u = usuarios->find(new KeyString(autor));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");
	if (u == NULL) throw std::invalid_argument("El usuario no existe");

	p->agregarComentario(padres, texto, u);
}

ICollection* Sistema::ListarSalas(int idCine) {
	Cine* c = cines->find(new KeyInteger(idCine));

	if (c == NULL) throw std::invalid_argument("El cine no existe");

	return c->ListarSalas();
}

void Sistema::CrearReserva(int cantAsientos, float costo, string titulo, int idFuncion, string usuario, string banco, string financiera, int descuento) {
	Pelicula* p = peliculas->find(new KeyString(titulo));
	Usuario* u = usuarios->find(new KeyString(usuario));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");
	if (u == NULL) throw std::invalid_argument("El usuario no existe");
	
	p->CrearReserva(cantAsientos, costo, idFuncion, u, banco, financiera, descuento);
}

int Sistema::ObtenerDescuentoFinanciera(string financiera)
{
	int res;
	Financiera f;
	if (financiera == "Bacacay") f = Bacacay;
	if (financiera == "Banco Hipotecario") f = Banco_Hipotecario;
	if (financiera == "Cambio Maiorano") f = Cambio_Maiorano;

	switch (f)
	{
	case Bacacay:
		res = 20;
		break;
	case Banco_Hipotecario:
		res = 15;
		break;
	case Cambio_Maiorano:
		res = 10;
		break;
	default:
		res = 0;
		break;
	}
	return res;
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

void Sistema::VerComentariosyPuntajes(string titulo) {
	Pelicula* p = peliculas->find(new  KeyString(titulo));
	cout << p->getTitulo() << endl << endl;
	cout << "Puntaje promedio: " << p->getPuntaje() << " (" << p->getCantPuntajes() << " usuarios)"<< endl << endl;

	ListarComentarios(titulo);
	cout << endl;
	ListarPuntajes(titulo);
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
    while (it.hasCurrent()) {
		Cine* c = it.getCurrent();
        ids->add(new DtCine(c->getIdCine(), c->getDireccion()));
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

int Sistema::YaPuntuo(string pelicula, string usuario) {
	Pelicula* p = peliculas->find(new KeyString(pelicula));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");

	return p->YaPuntuo(usuario);
}

void Sistema::VerReservasPorUsuario(string usuario)
{
	PeliculaIterator it = peliculas->getIterator();
	while (it.hasCurrent()) {
		Pelicula* p = it.getCurrent();
		p->ListarReservas(usuario);
		it.next();
	}
}

void Sistema::ListarComentarios(string titulo) {
	Pelicula* p = peliculas->find(new KeyString(titulo));

	if (p == NULL) throw std::invalid_argument("La pelicula no existe");
	ICollection* com = p->ListarComentarios();
	IIterator* it = com->getIterator();
	cout << "Comentarios" << endl;
	if (com->isEmpty()) cout << "No hay comentarios" << endl;

	while (it->hasCurrent()) {
		DtComentario* c = dynamic_cast<DtComentario*>(it->getCurrent());
		cout << "<" << c->getDtUsuario().getNickName() << ">" << ":" << "   " << c->getTexto() << endl;
		MostrarHijosComentario(c, 1);
		it->next();
	}

}
void Sistema::MostrarHijosComentario(DtComentario* com, int cantE) {
	ICollection* hijos = com->getHijos();

	if (hijos->isEmpty()) {
		//Termina la operacion
	}
	else {
		string espacios = "";
		for (int i = 0; i < cantE; i++)
		{
			espacios += "  "; //Simplemente espacios para diferenciar entre respuestas y comentarios base
		}

		IIterator* it = hijos->getIterator();
		while (it->hasCurrent()) {
			DtComentario* c = dynamic_cast<DtComentario*>(it->getCurrent());
			cout << espacios << "<" << c->getDtUsuario().getNickName() << ">" << ":" << "   " << c->getTexto() << endl;
			MostrarHijosComentario(c, cantE+1);
			it->next();
		}
	}
}
void Sistema::ListarPuntajes(string titulo){
    Pelicula* p = peliculas->find(new KeyString(titulo));

    if (p == NULL) throw std::invalid_argument("La pelicula no existe");
    ICollection* Pun= new List();
    Pun=p->ListarPuntajes();
    IIterator* it = Pun->getIterator();
	cout << "Puntajes" << endl;
	if (Pun->isEmpty()) cout << "No hay puntajes" << endl;

    while (it->hasCurrent()) {
        DtPuntaje* pu = dynamic_cast<DtPuntaje*>(it->getCurrent());
        cout << "<"<< pu->getDtUsuario().getNickName() <<">"<<":"<< "<" <<pu->getValor()<< ">" << endl;
        it->next();
    }
}
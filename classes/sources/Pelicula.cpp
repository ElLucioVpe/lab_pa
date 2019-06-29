#include "../headers/Pelicula.h"

Pelicula::Pelicula(string titulo, string poster, string sinopsis, float puntaje){
  this->titulo=titulo;
  this->poster=poster;
  this->sinopsis=sinopsis;
  this->puntaje=puntaje;
  puntajes= new ColPuntajes;
  funciones= new ColFunciones;
  comentarios = new ColComentarios;

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

float Pelicula::getPuntaje(){
    float _puntajeTotal = 0;
    int _contador = 0;

    PuntajeIterator _iterator = puntajes->getIterator();

    while (_iterator.hasCurrent()) {
        Puntaje* p = dynamic_cast<Puntaje*>(_iterator.getCurrent());

        _puntajeTotal += p->getValor();
        _contador++;

        _iterator.next();
    }

    if(_contador > 0) {
         return _puntajeTotal / _contador;
    } else {
        return _puntajeTotal;
    }
}

void Pelicula::setTitulo(string titulo){
	this->titulo=titulo;
}
void Pelicula::setPoster(string Poster) {
	this->poster = Poster;
}
void Pelicula::setSinopsis(string sinopsis){
	this->sinopsis=sinopsis;
}

void Pelicula::puntuarPelicula(int valorPuntaje, Usuario* user) {
	Puntaje* puntajeNuevo = new Puntaje(valorPuntaje, user);
    puntajes->add(puntajeNuevo);
}

void Pelicula::CrearReserva(int cantAsientos, float costo, int idFuncion, string usuario, string banco, string financiera)
{
	Funcion* f = funciones->find(new KeyInteger(idFuncion));

	if (f == NULL) throw std::invalid_argument("La funcion no existe");

	int disponibles, asientosSala;
	asientosSala = f->getSala()->getCantAsientos();
	disponibles = asientosSala - f->AsientosReservados();

	if ((disponibles + cantAsientos) > asientosSala) throw std::invalid_argument("No quedan suficientes asientos para reservar");

	f->ReservarFuncion(cantAsientos, costo, usuario, banco, financiera);
}

void Pelicula::EliminarFunciones()
{
	FuncionIterator it = funciones->getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		f->~Funcion();
		it.next();
	}
}

void Pelicula::AltaFuncion(string horario, Cine* cin, Sala* sal) {

int id = funciones->getSize() + 1;
KeyInteger* k = new KeyInteger(id);

Funcion* f = new Funcion(id,horario,cin,sal);
funciones->add(k,f);


}

ICollection* Pelicula::ListarFunciones(int idCine)
{
	ICollection* dts = new List();
	FuncionIterator it = funciones->getIterator();

	time_t tiempoActual;
	time(&tiempoActual);

	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		if (f->EsDeCine(idCine) && f->getHorario() < tiempoActual) dts->add(new DtFuncion(f->getIdFuncion(), f->getHorario(), f->getSala()->getIdSala()));

		it.next();
	}

	return dts;
}

ICollection* Pelicula::ListarComentarios() {
	ICollection* dts = new List();
	ComentarioIterator it = comentarios->getIterator();
	while (it.hasCurrent()) {
		Comentario* c = it.getCurrent();
		Usuario* u = c->getAutor();
		dts->add(new DtComentario(c->getId(), c->getTexto(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin())));
		it.next();
	}

	return dts;
}

ICollection* Pelicula::getCines()
{
	ICollection* dts = new List();
	FuncionIterator it = funciones->getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		dts->add(new DtCine(f->getCines()->getIdCine(), f->getCines()->getDireccion()));
		it.next();
	}

	return dts;
}

void Pelicula::agregarComentario(string _comentario, Usuario* autor)
{

   int _number = comentarios->getSize() + 1;
   Comentario* _com = new Comentario(_number, _comentario, autor);
   comentarios->add(new KeyInteger(_number), _com);
}


ICollection* Pelicula::getComentarios()
{
   ICollection* dts = new List();
   ComentarioIterator it = comentarios->getIterator();
   while (it.hasCurrent()) {
      Comentario* c = it.getCurrent();
      dts->add(new DtComentario(c->getId(), c->getTexto()));
      it.next();
   }

   return dts;
}

Funcion* Pelicula::getFuncion(int idFuncion)
{
	return funciones->find(new KeyInteger(idFuncion));
}

Pelicula::~Pelicula() {
	delete funciones; //el destructor de cada funcion ya se encarga de eliminar las reservas en dicha funcion 
	delete puntajes;
	delete comentarios;
}

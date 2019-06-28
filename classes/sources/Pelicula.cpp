#include "../headers/Pelicula.h"

Pelicula::Pelicula(string titulo, string poster, string sinopsis, float puntaje){
  this->titulo=titulo;
  this->poster=poster;
  this->sinopsis=sinopsis;
  this->puntaje=puntaje;
  this->puntajes= new *ColPuntajes;
  this->funciones= new *ColFunciones;
   this->comentarios = new *ColComentarios;

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

    PuntajeIterator _iterator = this->puntajes.getIterator();

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

void Pelicula::puntuarPelicula(int valorPuntaje, DtUsuario* user) {
    Puntaje* puntajeNuevo;
    puntajeNuevo = new Puntaje(valorPuntaje, *this, user);
    this->puntajes.add(puntajeNuevo);
}

void Pelicula::CrearReserva(int cantAsientos, float costo, int idFuncion, string usuario, string banco, string financiera)
{
	Funcion* f = funciones.find(new KeyInteger(idFuncion));
	f->ReservarFuncion(cantAsientos, costo, usuario, banco, financiera);
}

void Pelicula::EliminarFunciones()
{
	FuncionIterator it = funciones.getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		f->~Funcion();
		it.next();
	}
}

ICollection* Pelicula::ListarFunciones(int idCine)
{
	ICollection* dts = new List();
	FuncionIterator it = funciones.getIterator();

	time_t tiempoActual;
	time(&tiempoActual);

	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		if (f->EsDeCine(idCine) && f->getHorario() < tiempoActual) dts->add(new DtFuncion(f->getIdFuncion(), f->getHorario()));

		it.next();
	}

	return dts;
}

ICollection* Pelicula::getCines()
{
	ICollection* dts = new List();
	FuncionIterator it = funciones.getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		dts->add(new DtCine(f->getCines()->getIdCine(), f->getCines()->getDireccion()));
		it.next();
	}

	return dts;
}

void Pelicula::agregarComentario(string _comentario)
{
   int _number = this->comentarios.getSize() + 1;
   KeyString _key = std::to_string(_number);
   Comentario* _com = new Comentario(_comentario);
   this->comentarios.add(&_key, _com);
}

ICollection* Pelicula::getComentarios()
{
   ICollection* dts = new List();
   ComentarioIterator it = comentarios.getIterator();
   while (it.hasCurrent()) {
      Comentario* c = it.getCurrent();
      dts->add(new DtComentario(c->getId(), c->getTexto()));
      it.next();
   }

   return dts;
}

Pelicula::~Pelicula() {
	EliminarFunciones();
}

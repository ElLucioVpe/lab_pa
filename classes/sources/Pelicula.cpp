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

int Pelicula::getCantPuntajes() {
	return puntajes->getSize();
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

	PuntajeIterator it = puntajes->getIterator();
	while (it.hasCurrent()) {
		Puntaje* p = it.getCurrent();
		if (p->getUsuario() == user) {
			p->setValor(valorPuntaje);
			return;
		}
		it.next();
	}

    puntajes->add(puntajeNuevo);
}

void Pelicula::CrearReserva(int cantAsientos, float costo, int idFuncion, Usuario* usuario, string banco, string financiera, float descuento)
{
	Funcion* f = funciones->find(new KeyInteger(idFuncion));

	if (f == NULL) throw std::invalid_argument("La funcion no existe");

	int disponibles, asientosSala;
	Sala* s = f->getSala();
	asientosSala = s->getCantAsientos();
	disponibles = asientosSala - f->AsientosReservados();

	if ((disponibles + cantAsientos) < asientosSala) throw std::invalid_argument("No quedan suficientes asientos para reservar");

	f->ReservarFuncion(cantAsientos, costo, usuario, banco, financiera, descuento);
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
		if (f->EsDeCine(idCine) && (f->getHorario() >= tiempoActual)) dts->add(new DtFuncion(f->getIdFuncion(), f->getHorario(), f->getSala()->getIdSala()));

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
		ICollection* hijosdt = c->ListarHijos();
		dts->add(new DtComentario(c->getId(), c->getTexto(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin()), hijosdt));
		it.next();
	}

	return dts;
}
ICollection* Pelicula::ListarPuntajes(){
    ICollection* dts = new List();
    PuntajeIterator it = puntajes->getIterator();
    while (it.hasCurrent()) {
        Puntaje* c = it.getCurrent();
        Usuario* u = c->getUsuario();
        dts->add(new DtPuntaje(c->getValor(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin())));
        it.next();
    }

    return dts;
}
ICollection* Pelicula::getCines()
{
	ICollection* dts = new List();
	ICollection* auxCines = new List();
	FuncionIterator it = funciones->getIterator();

	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		Cine* c = f->getCines();
		if (!auxCines->member(c)) { //Para evitar cines repetidos
			DtCine* dtc = new DtCine(c->getIdCine(), c->getDireccion());
			dts->add(dtc);
		}
		auxCines->add(c);
		it.next();
	}
	delete auxCines;
	return dts;
}

int Pelicula::YaPuntuo(string user)
{
	PuntajeIterator it = puntajes->getIterator();
	while (it.hasCurrent()) {
		Puntaje* p = it.getCurrent();
		if (p->getUsuario()->getNickName() == user) return p->getValor();
		it.next();
	}
	return 0; //Si no existe puntuacion del usuario
}

void Pelicula::ListarReservas(string user)
{
	FuncionIterator it = funciones->getIterator();
	while (it.hasCurrent()) {
		Funcion* f = it.getCurrent();
		ICollection* res = f->ListarReservas(user);
		IIterator* resit = res->getIterator();

		while (resit->hasCurrent()) {
			const time_t h = f->getHorario();
			cout << "---- Reserva ----" << endl;
			cout << "Pelicula: " << this->titulo << endl;
			cout << "Funcion: " << to_string(f->getIdFuncion()) << endl;
			cout << "Fecha y Hora: " << ctime(&h); //hace el << endl solo
			cout << "Sala: " << to_string(f->getSala()->getIdSala()) << endl;
			cout << "Cine: " << to_string(f->getCines()->getIdCine()) << endl;
			DtTarjetaDeCredito* t = dynamic_cast<DtTarjetaDeCredito*>(resit->getCurrent());
			if (t) {
				cout << "Tipo de Pago: Tarjeta de Credito" << endl;
				cout << "Cantidad de Asientos: " << to_string(t->getCantidadAsientos()) << endl;
				cout << "Costo: " << to_string(t->getPrecio()) << endl << endl;
			}
			else {
				auto d = (DtTarjetaDeDebito*) resit->getCurrent();
				cout << "Tipo de Pago: Tarjeta de Debito" << endl;
				cout << "Cantidad de Asientos: " << to_string(d->getCantidadAsientos()) << endl;
				cout << "Costo: " << to_string(d->getPrecio()) << endl << endl;
			}
			resit->next();
		}
		it.next();
	}
}

void Pelicula::agregarComentario(vector<int> padres,string _comentario, Usuario* autor)
{
	Comentario* _com = new Comentario(0, _comentario, autor); //Asigno 0 para luego cambiarlo mediante un set
	if (padres.size() == 0) {
		int _number = comentarios->getSize() + 1;
		_com->setId(_number);
		comentarios->add(new KeyInteger(_number), _com);
	}
	else {
		//Si es una respuesta
		Comentario* cpadre = comentarios->find(new KeyInteger(padres[0]));

		if (cpadre == NULL) throw std::invalid_argument("El comentario no existe");

		padres.erase(padres.begin());
		cpadre->agregarHijo(padres, _com);
	}
}

Pelicula::~Pelicula() {
	delete funciones; //el destructor de cada funcion ya se encarga de eliminar las reservas en dicha funcion 
	delete puntajes;
	delete comentarios;
}

#include "../headers/Funcion.h"
#include "../headers/TarjetaDeCredito.h"
#include "../headers/TarjetaDeDebito.h"

Funcion::Funcion(int IdFuncion, string _horario, Cine* _cine, Sala* _sala){
	this->IdFuncion= IdFuncion;
	this->_cine = _cine;
	this->_sala = _sala;

	//Conversion de string a time_t
	time_t horario;
	int yy, month, dd, hh, mm, ss;
	struct tm horariotm = { 0 };

	sscanf(_horario.c_str(), "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
	horariotm.tm_year = yy - 1900;
	horariotm.tm_mon = month - 1;
	horariotm.tm_mday = dd;
	horariotm.tm_hour = hh;
	horariotm.tm_min = mm;
	horariotm.tm_sec = ss;
	horariotm.tm_isdst = -1;

	horario = mktime(&horariotm);
	this->Horario= horario;
	reservas = new ColReservas();
}

int Funcion::getIdFuncion(){
	return this->IdFuncion;
}

time_t Funcion::getHorario(){
	return this->Horario;
}
Cine* Funcion::getCines(){
	return this->_cine;
}
Sala* Funcion::getSala()
{
	return this->_sala;
}
void Funcion::setIdfuncion(int IdFuncion){
	this->IdFuncion= IdFuncion;
}
void Funcion::setHorario(time_t Horario){
	this->Horario= Horario;
}
void Funcion::EliminarReservas() {
	delete reservas;
}
bool Funcion::EsDeCine(int idCine)
{
	return _cine->getIdCine() == idCine;
}
void Funcion::ReservarFuncion(int cantAsientos, float costo, Usuario* user, string banco, string financiera, float descuento) {
	
	if (banco == "") reservas->add(new TarjetaDeCredito(financiera, descuento, costo, cantAsientos, user));
	else reservas->add(new TarjetaDeDebito(banco, costo, cantAsientos, user));

	//se deberia agregar un parametro Usuario a Reserva o alguna otra forma de saber quien la reservo
}

int Funcion::AsientosReservados()
{
	int cant = 0;
	ReservaIterator it = reservas->getIterator();
	while (it.hasCurrent()) {
		Reserva* r = it.getCurrent();
		cant += r->getCantidadAsientos();
		it.next();
	}

	return cant;
}

ICollection* Funcion::ListarReservas(string user)
{
	ICollection* dts = new List();
	ReservaIterator it = reservas->getIterator();
	while (it.hasCurrent()) {
		
		TarjetaDeCredito* c = dynamic_cast<TarjetaDeCredito*>(it.getCurrent());
		Usuario* u = c->getUsuario();
		if (user == u->getNickName()) {
			if (c) {
				dts->add(new DtTarjetaDeCredito(c->getFinanciera(), c->getDescuento(), c->getPrecio(), c->getCantidadAsientos(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin())));
			}
			else {
				auto d = (DtTarjetaDeDebito*) it.getCurrent();
				dts->add(new DtTarjetaDeDebito (d->getBanco() , d->getPrecio(), d->getCantidadAsientos(), DtUsuario(u->getNickName(), u->getImgPerfil(), u->getContrasenia(), u->getAdmin())));
			}
		}
		it.next();
	}
	return dts;
}

Funcion::~Funcion()
{
	EliminarReservas();
}

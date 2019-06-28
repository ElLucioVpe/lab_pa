#include "../headers/DtFuncion.h"

DtFuncion::DtFuncion(){

}

DtFuncion::DtFuncion(int idFuncion, time_t horario, int idSala) {
    this->idFuncion = idFuncion;
    this->horario = horario;
	this->idSala = idSala;
}

int DtFuncion::getIdFuncion() const {
    return this->idFuncion;
}

time_t DtFuncion::getHorario() const {
    return this->horario;
}

int DtFuncion::getIdSala()
{
	return this->idSala;
}

bool DtFuncion::operator<(const DtFuncion& f) const
{
	if (idFuncion < f.getIdFuncion())
		return true;
	else
		return false;
}

DtFuncion::~DtFuncion() {
}

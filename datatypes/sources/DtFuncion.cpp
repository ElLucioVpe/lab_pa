#include "../headers/DtFuncion.h"

DtFuncion::DtFuncion(){

}

DtFuncion::DtFuncion(int idFuncion, string horario)
  {
    this->idFuncion = idFuncion;
    this->horario = horario;
    }

int DtFuncion::getIdFuncion() const {
    return this->idFuncion;
}

string DtFuncion::getHorario() const {
    return this->horario;
}

DtFuncion::~DtFuncion() {
}

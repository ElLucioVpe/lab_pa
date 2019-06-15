#include "../headers/DtFuncion.h"

DtFuncion::DtFuncion(){

}

DtFuncion::DtFuncion(int idFuncion, date horario)
  {
    this->idFuncion = idFuncion;
    this->horario = horario;
    }

    string DtFuncion::getIdFuncion() const {
    return this->idFuncion;
}

string DtFuncion::getHorario() const {
    return this->horario;
}

DtFuncion::~DtFuncion() {
}

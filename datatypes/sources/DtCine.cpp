#include "../headers/DtCine.h"

DtCine::DtCine(){

}

DtCine::DtCine(int idCine, string direccion)
  {
    this->idCine = idCine;
    this->direccion = direccion;
    }

    string DtCine::getIdCine() const {
    return this->idCine;
}

string DtCine::getDireccion() const {
    return this->direccion;
}

DtCine::~DtCine() {
}

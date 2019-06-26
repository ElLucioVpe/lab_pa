#include "../headers/DtCine.h"

DtCine::DtCine(){

}

DtCine::DtCine(int idCine, string direccion){
    this->idCine = idCine;
    this->direccion = direccion;
}

int DtCine::getIdCine() const {
    return this->idCine;
}

string DtCine::getDireccion() const {
    return this->direccion;
}

bool DtCine::operator<(const DtCine& c) const{
	if (idCine < c.getIdCine())
		return true;
	else
		return false;
}

DtCine::~DtCine() {
}

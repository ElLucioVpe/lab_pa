//INCLUDE HEADER

Reserva::Reserva(float prec, int cantAsientos ){
    this->precio = prec;
    this->cantidadAsientos = cantAsientos;
}

int Reserva::getPrecio() const {
    return this->Precio;
}

int Reserva::getCantidadAsientos() const {
    return this->cantidadAsientos;
}

Reserva::~Reserva() {
}


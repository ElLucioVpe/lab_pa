//INCLUDE HEADER

Reserva::Reserva(float prec, int cantAsientos ){
    this->precio = prec;
    this->cantidadAsientos = cantAsientos;
}

float Reserva::getPrecio() const {
    return this->precio;
}

int Reserva::getCantidadAsientos() const {
    return this->cantidadAsientos;
}

Reserva::~Reserva() {
}


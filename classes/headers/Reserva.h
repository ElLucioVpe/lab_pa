#ifndef RESERVA_H
#define RESERVA_H



class Reserva {
public:
    Reserva(int, int);
    int getId() const;
    int getCantidadAsientos() const;
    
    virtual DtReserva* getDtReserva() = 0;
    virtual ~Reserva();
private:
    int id;
    int cantidadAsientos;
};

#endif /* RESERVA_H */


#ifndef ISISTEMA_H
#define	ISISTEMA_H

#include <iostream>
#include <set>
#include "../classes/headers/Usuario.h"
#include "../datatypes/headers/DtPelicula.h"
#include "../datatypes/headers/DtCine.h"
#include "../datatypes/headers/DtFuncion.h"

class ISistema {
    public:
        virtual bool iniciarSesion(string , string) = 0;
        virtual void CrearReserva(int, float, int, Usuario) = 0;
        virtual set<string> ListarTitulos() = 0;
        virtual DtPelicula SeleccionarPelicula(string) = 0;
        virtual void EliminarPelicula(string) = 0;
        virtual void VerInfoPelicula(string) = 0;
        virtual set<string> ListarCines() = 0;
        virtual set<DtCine> ListarCinesPorTitulo(string) = 0;
        virtual set<DtFuncion> ListarFunciones(int, string) = 0;
        virtual ~ISistema();
};

#endif	/* ISISTEMA_H */
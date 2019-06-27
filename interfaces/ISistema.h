#ifndef ISISTEMA_H
#define	ISISTEMA_H

#include <iostream>
#include <set>
#include "../classes/headers/Usuario.h"
#include "../datatypes/headers/DtPelicula.h"
#include "../datatypes/headers/DtCine.h"
#include "../datatypes/headers/DtFuncion.h"
#include "../datatypes/headers/DtUsuario.h"

class ISistema {
    public:
		virtual void AltaUsuario(string nick, string img, string contra) = 0;
		virtual void AltaPelicula(string titulo, string poster, string sinopsis) = 0;
		virtual void AltaCine(string dir) = 0;
        virtual DtUsuario* iniciarSesion(string , string) = 0;
        virtual void CrearReserva(int cantAsientos, float costo, string titulo, int IdFuncion, string usuario, string banco, string financiera) = 0;
        virtual ICollection* ListarTitulos() = 0;
        virtual DtPelicula* SeleccionarPelicula(string) = 0;
        virtual void EliminarPelicula(string) = 0;
        virtual void VerInfoPelicula(string) = 0;
        virtual ICollection* ListarCines() = 0;
        virtual ICollection* ListarCinesPorTitulo(string) = 0;
        virtual ICollection* ListarFunciones(int, string) = 0;
        virtual ~ISistema();
};

#endif	/* ISISTEMA_H */
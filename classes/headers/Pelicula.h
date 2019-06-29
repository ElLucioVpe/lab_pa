#ifndef PELICULA_H
#define PELICULA_H

#include <iostream>
#include <set>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColFunciones.h"
#include "../../collections/ColPuntajes.h"
#include "../../collections/ColComentarios.h"
#include "../../datatypes/headers/DtFuncion.h"
#include "../../datatypes/headers/DtComentario.h"
#include "../../datatypes/headers/DtCine.h"

using namespace std;

class Pelicula : public ICollectible {
public:
	Pelicula(string titulo, string poster, string sinopsis, float puntaje);

	string getTitulo();
	string getPoster();
	string getSinopsis();
	float getPuntaje();
	void setTitulo(string titulo);
	void setPoster(string poster);
	void setSinopsis(string sinopsis);

    void CrearReserva(int cantAsientos, float costo, int idFuncion, string usuario, string banco, string financiera);
	void agregarComentario(string _comentario, Usuario* autor);
    void EliminarFunciones();
	void AltaFuncion(string horario, Cine* cin, Sala* sal);
    void puntuarPelicula(int puntaje, Usuario* user);
    ICollection* ListarFunciones(int IdCine);
    ICollection* ListarComentarios(string titulo);
    ICollection* getCines();
    ICollection* ListarPuntajes();
	int YaPuntuo(string user);
	~Pelicula();

private:
	string titulo;
	string poster;
	string sinopsis;
	float puntaje;
	ColFunciones* funciones;
	ColPuntajes* puntajes;
    ColComentarios* comentarios;
};

#endif	/* PELICULA_H */

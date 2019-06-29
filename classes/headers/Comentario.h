#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColComentarios.h"
#include "../../classes/headers/Usuario.h"
#include "../../datatypes/headers/DtComentario.h"

class ColComentarios;

using namespace std;

class Comentario : public ICollectible {
public:
	Comentario(int id, string Texto, Usuario* autor);
	int getId();
	string getTexto();
	Usuario* getAutor();
	void setId(int _id);
	void setTexto(string t);
	void setUsuario(string u);
	void agregarHijo(Comentario* c);
	~Comentario();
private:
	int Id;
	string Texto;
	Usuario* Autor;
	ColComentarios* hijos;
};

#endif /* COMENTARIO_H */
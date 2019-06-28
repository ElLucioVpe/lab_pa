#ifndef COLCOMENTARIO_H
#define COLCOMENTARIO_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColComentarios.h"
#include "../../classes/headers/Usuario.h"

using namespace std;

class Comentario : public ICollectible {
public:
	Comentario(int id, string Texto, Usuario* autor);
	int getId();
	string getTexto();
	Usuario GetUsuario();
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

#endif /* COLCOMENTARIO_H */

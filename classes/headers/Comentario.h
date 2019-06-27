#ifndef COLCOMENTARIO_H
#define COLCOMENTARIO_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../collections/ColComentarios.h"

using namespace std;

class Comentario : public ICollectible {
public:
	Comentario(string Texto);
	int getId();
	string getTexto();
	void setId(int _id);
	void setTexto(string t);
	void agregarHijo(Comentario* c);
	~Comentario();
private:
	int Id;
	string Texto;
	ColComentarios* hijos;
};

#endif /* COLCOMENTARIO_H */

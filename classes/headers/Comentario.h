#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
#include "../../interfaces/ICollectible.h"
#include "../../classes/headers/Usuario.h"
//#include "../../collections/ColComentarios.h"
#include "../../collections/OrderedDictionary.h"
#include "../../KeyInteger.h"

//class ColComentarios;

using namespace std;

class Comentario : public ICollectible {
public:
	Comentario(int id, string Texto, Usuario* autor);
	int getId();
	string getTexto();
	Usuario* getAutor();
	void setId(int _id);
	void setTexto(string t);
	void setUsuario(Usuario* u);
	void agregarHijo(Comentario* c);
	Icollection * ListarHijos(string c);
	~Comentario();
private:
	int Id;
	string Texto;
	Usuario* Autor;
	IDictionary* hijos;
};

#endif /* COMENTARIO_H */
#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <iostream>
#include <vector>
#include "../../interfaces/ICollectible.h"
#include "../../classes/headers/Usuario.h"
#include "../../collections/OrderedDictionary.h"
#include "../../collections/List.h"
#include "../../KeyInteger.h"
#include "../../datatypes/headers/DtComentario.h"

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
	void agregarHijo(vector<int> padres, Comentario* c);
	ICollection * ListarHijos();
	~Comentario();
private:
	int Id;
	string Texto;
	Usuario* Autor;
	IDictionary* hijos;
};

#endif /* COMENTARIO_H */
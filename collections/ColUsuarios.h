#ifndef COLUSUARIOS_H
#define COLUSUARIOS_H

#include <iostream>
#include <string>
#include "../classes/headers/Usuario.h"
#include "UsuarioIterator.h"
#include "OrderedDictionary.h"
#include "../String.h"

class ColUsuarios {
private:
    IDictionary* usuarios;

public:
    ColUsuarios();
    ~ColUsuarios();

    void add(String* k,Usuario * u);
    void remove(String* k);
    bool member(String* k);
	Usuario* find(String* k);
    bool isEmpty() const;
    int getSize() const;
    UsuarioIterator getIterator();
};

#endif /* COLUSUARIOS_H */

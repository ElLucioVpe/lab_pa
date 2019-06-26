#ifndef COLUSUARIOS_H
#define COLUSUARIOS_H

#include <iostream>
#include <string>
#include "../classes/headers/Usuario.h"
#include "UsuarioIterator.h"
#include "OrderedDictionary.h"
#include "../KeyString.h"

class ColUsuarios {
private:
    IDictionary* usuarios;

public:
    ColUsuarios();
    ~ColUsuarios();

    void add(KeyString* k,Usuario * u);
    void remove(KeyString* k);
    bool member(KeyString* k);
	Usuario* find(KeyString* k);
    bool isEmpty() const;
    int getSize() const;
    UsuarioIterator getIterator();
};

#endif /* COLUSUARIOS_H */

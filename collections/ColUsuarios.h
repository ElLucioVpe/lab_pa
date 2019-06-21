#ifndef COLUSUARIOS_H
#define COLUSUARIOS_H

#include <iostream>
#include <string>
#include "../classes/headers/Usuario.h"
#include "../interfaces/ICollection.h"
#include "UsuarioIterator.h"
#include "List.h"

class ColUsuarios {
private:
    ICollection* usuarios;

public:
    ColUsuarios();
    ~ColUsuarios();

    void add(Usuario * u);
    void remove(Usuario * u);
    bool member(Usuario * u);
    bool isEmpty() const;
    int getSize() const;
    UsuarioIterator getIterator();
};

#endif /* COLUSUARIOS_H */

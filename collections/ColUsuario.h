#ifndef COLUSUARIO_H
#define COLUSUARIO_H

#include <iostream>
#include <string>
#include "../classes/headers/Usuario.h"
#include "../interfaces/ICollection.h"
#include "List.h"

class ColUsuario {
private:
    static ColUsuario* instance;
    ICollection* usuarios;

public:
    ColUsuario()
    ~ColUsuario();
    static ColUsuario* getInstance();

    void add(Usuario * u);
    void remove(Usuario * u);
    bool member(Usuario * u);
    bool isEmpty() const;
    int getSize() const;
};
       
}

#endif /* COLUSUARIO_H */
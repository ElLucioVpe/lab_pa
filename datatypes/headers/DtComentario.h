//
// Created by lucianoporta on 6/27/2019.
//

#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H

#include <iostream>
#include "../../classes/headers/Comentario.h"
#include "../../interfaces/ICollectible.h"
#include "DtUsuario.h"

using namespace std;

class DtComentario : public ICollectible {
public:
    DtComentario();
    DtComentario(int, string, DtUsuario);
    string getTexto();
    int getId();
    DtUsuario getDtUsuario();
    virtual ~DtComentario();
private:
    int id;
    string texto;
    DtUsuario user;
};

#endif //DTCOMENTARIO_H

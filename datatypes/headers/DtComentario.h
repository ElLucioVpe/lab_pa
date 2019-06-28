//
// Created by lucianoporta on 6/27/2019.
//

#ifndef DTCOMENTARIO_H

#include <iostream>
#include "../../classes/headers/Comentario.h"
#include "../../interfaces/ICollectible.h"
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

#define DTCOMENTARIO_H

#endif //DTCOMENTARIO_H

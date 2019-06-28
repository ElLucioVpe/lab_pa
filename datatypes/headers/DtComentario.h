//
// Created by lucianoporta on 6/27/2019.
//

#ifndef DTCOMENTARIO_H

#include <iostream>
#include "../../classes/headers/Comentario.h"
using namespace std;

class DtComentario: public ICollectible {
public:
    DtComentario();
    DtComentario(int, string);
    string getTexto();
    int getId();
    virtual ~DtComentario();
private:
    int id;
    string texto;
};

#define DTCOMENTARIO_H

#endif //DTCOMENTARIO_H

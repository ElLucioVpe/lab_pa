//
// Created by lucianoporta on 6/27/2019.
//

#ifndef DTCOMENTARIO_H

#include <iostream>
using namespace std;

class DtComentario {
public:
    DtComentario();
    DtComentario(int, string);
    string getTexto();
    int getId();
    virtual ~DtPelicula();
private:
    int id;
    string texto;
};

#define DTCOMENTARIO_H

#endif //DTCOMENTARIO_H

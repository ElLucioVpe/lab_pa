//
// Created by Xavel on 29/06/2019.
//

#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H

#include <iostream>
#include "../../classes/headers/Puntaje.h"
#include "../../interfaces/ICollectible.h"
#include "DtUsuario.h"
using namespace std;

class DtPuntaje : public ICollectible {
public:
    DtPuntaje();
    DtPuntaje(int, DtUsuario);
    int getValor();
    DtUsuario getDtUsuario();
    virtual ~DtPuntaje();
private:
    int Valor;
    DtUsuario user;
};

#endif //DTPUNTAJE_H

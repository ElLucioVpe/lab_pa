#ifndef COLPUNTAJES_H
#define	COLPUNTAJES_H

#include <iostream>
#include <string>
#include "../classes/headers/Puntaje.h"
#include "../interfaces/ICollection.h"
#include "PuntajeIterator.h"
#include "List.h"

class ColPuntajes {
    private:
        ICollection* puntajes;
    public:
      ColPuntajes();
      ~ColPuntajes();

      void add(Puntaje * p);
      void remove(Puntaje * p);
      bool member(Puntaje * p);
      bool isEmpty() const;
      int getSize() const;
      PuntajeIterator getIterator();
  };

  #endif	/* COLPUNTAJES_H */

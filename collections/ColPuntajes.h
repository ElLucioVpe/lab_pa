#ifndef COLPUNTAJES_H
#define	COLPUNTAJES_H

#include "../interfaces/ICollection.h"
#include "FuncionIterator.h"
#include "../classes/headers/Puntaje.h"
#include "OrderedDictionary.h"
#include "List.h"
#include "../KeyString.h"


class ColPuntajes_H {
private:
    IDictionary* puntajes
  public:
      ColPuntajes();
      ~ColPuntajes();
      void add(KeyString * k,Puntaje * p);
      void remove(KeyString * k);
      bool member(KeyString * k);
      Puntaje* find(KeyString* k);
      bool isEmpty() const;
      int getSize() const;
      ComentarioIterator getIterator();
  };

  #endif	/* COLPUNTAJES_H */

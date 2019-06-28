#ifndef COLDTCOMENTARIOS_H
#define	COLDTCOMENTARIOS_H

#include "../interfaces/ICollection.h"
#include "ComentarioIterator.h"
#include "../classes/headers/DtComentario.h"
#include "OrderedDictionary.h"
#include "../KeyInteger.h"

class ColDtComentarios {
private:
	IDictionary* DtComentarios;
  public:
    ColDtComentarios();
      ~ColDtComentarios();
      void add(KeyInteger* k,DtComentario * c);
      void remove(KeyInteger* k);
      bool member(KeyInteger* k);
      DtComentario* find(KeyInteger* k);
      bool isEmpty() const;
      int getSize() const;
      DtComentarioIterator getIterator();
  };

  #endif	/* COLPELICULAS_H */

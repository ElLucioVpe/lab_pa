#ifndef COLCOMENTARIOS_H
#define	COLCOMENTARIOS_H

#include "../interfaces/ICollection.h"
#include "ComentarioIterator.h"
//#include "../classes/headers/Comentario.h"
#include "OrderedDictionary.h"
#include "../KeyInteger.h"

class Comentario;

class ColComentarios {
private:
	IDictionary* comentarios;
  public:
	  ColComentarios();
      ~ColComentarios();
      void add(KeyInteger* k,Comentario * c);
      void remove(KeyInteger* k);
      bool member(KeyInteger* k);
      Comentario* find(KeyInteger* k);
      bool isEmpty() const;
      int getSize() const;
      ComentarioIterator getIterator();
  };

  #endif	/* COLPELICULAS_H */

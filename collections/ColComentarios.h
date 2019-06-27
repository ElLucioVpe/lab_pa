#ifndef COLCOMENTARIOS_H
#define	COLCOMENTARIOS_H

#include "../interfaces/ICollection.h"
#include "ComentarioIterator.h"
#include "../classes/headers/Comentario.h"
#include "OrderedDictionary.h"
#include "List.h"
#include "../KeyString.h"


class ColComentarios {
private:
	IDictionary* comentarios;
  public:
	  ColComentarios();
      ~ColComentarios();
      void add(KeyString * k,Comentario * c);
      void remove(KeyString * k);
      bool member(KeyString * k);
      Comentario* find(KeyString* k);
      bool isEmpty() const;
      int getSize() const;
      ComentarioIterator getIterator();
  };

  #endif	/* COLPELICULAS_H */

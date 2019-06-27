#ifndef COLCOMENTARIOS_H
#define	COLCOMENTARIOS_H

#include "../interfaces/ICollection.h"
#include "FuncionIterator.h"
#include "../classes/headers/Comentario.h"
#include "OrderedDictionary.h"
#include "List.h"
#include "../KeyString.h"


class ColComentarios_H {
private:
    IDictionary* comentarios
  public:
      ColPeliculas();
      ~ColPeliculas();
      void add(KeyString * k,Comentario * c);
      void remove(KeyString * k);
      bool member(KeyString * k);
      Comentario* find(KeyString* k);
      bool isEmpty() const;
      int getSize() const;
      ComentarioIterator getIterator();
  };

  #endif	/* COLPELICULAS_H */

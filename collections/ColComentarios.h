#ifndef COLCOMENTARIOS_H
#define	COLCOMENTARIOS_H

#include "../interfaces/ICollection.h"
#include "FuncionIterator.h"
#include "../classes/headers/Comentario.h"
#include "OrderedDictionary.h"
#include "List.h"


class ColComentarios_H {
private:
    IDictionary* comentarios
  public:
      ColPeliculas();
      ~ColPeliculas();
      void add(String * k,Comentario * c);
      void remove(String * k);
      bool member(String * k);
      Comentario* find(String* k);
      bool isEmpty() const;
      int getSize() const;
      ComentarioIterator getIterator();
  };

  #endif	/* COLPELICULAS_H */

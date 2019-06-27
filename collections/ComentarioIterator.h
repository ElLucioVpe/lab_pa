#ifndef COMENTARIOITERATOR_H
#define	COMENTARIOITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Comentario.h"

class ComentarioIterator {
public:
  ComentarioIterator();
  ComentarioIterator(IIterator* listIt);
  Comentario* getCurrent();
  bool hasCurrent();
  void next();
  ~ComentarioIterator();

Private:
IIterator* it;
};

#endif	/* PELICULAITERATOR_H */

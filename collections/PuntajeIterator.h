#ifndef PUNTAJEITERATOR_H
#define	PUNTAJEITERATOR_H

#include "ListIterator.h"
#include "../classes/headers/Puntaje.h"

class PuntajeIterator {
public:
  PuntajeIterator();
  PuntajeIterator(IIterator* listIt);
  Puntaje* getCurrent();
  bool hasCurrent();
  void next();
  ~PuntajeIterator();

Private:
IIterator* it;
};

#endif	/* PUNTAJEITERATOR_H */

CPP      = g++
CC       = gcc
OBJ      = main.o classes/sources/Cine.o classes/sources/Comentario.o classes/sources/Funcion.o classes/sources/Pelicula.o classes/sources/Puntaje.o classes/sources/Reserva.o classes/sources/Sala.o classes/sources/Sistema.o classes/sources/TarjetaDeCredito.o classes/sources/TarjetaDeDebito.o classes/sources/Usuario.o collections/ColPuntajes.o collections/ColComentarios.o collections/ColSalas.o collections/UsuarioIterator.o collections/SalaIterator.o collections/ReservaIterator.o collections/PuntajeIterator.o collections/PeliculaIterator.o collections/List.o collections/FuncionIterator.o collections/ComentarioIterator.o collections/ColUsuarios.o collections/ColReservas.o collections/ColPeliculas.o collections/ColFunciones.o collections/ColCines.o collections/CineIterator.o collections/OrderedDictionaryEntry.o collections/OrderedDictionary.o collections/ListNode.o collections/ListIterator.o datatypes/sources/DtCine.o datatypes/sources/DtComentario.o datatypes/sources/DtFuncion.o datatypes/sources/DtPelicula.o datatypes/sources/DtPuntaje.o datatypes/sources/DtSala.o datatypes/sources/DtUsuario.o interfaces/ISistema.o interfaces/OrderedKey.o interfaces/IKey.o interfaces/IIterator.o interfaces/IDictionary.o interfaces/ICollection.o interfaces/ICollectible.o KeyInteger.o KeyString.o String.o
LINKOBJ  = main.o classes/sources/Cine.o classes/sources/Comentario.o classes/sources/Funcion.o classes/sources/Pelicula.o classes/sources/Puntaje.o classes/sources/Reserva.o classes/sources/Sala.o classes/sources/Sistema.o classes/sources/TarjetaDeCredito.o classes/sources/TarjetaDeDebito.o classes/sources/Usuario.o collections/ColPuntajes.o collections/ColComentarios.o collections/ColSalas.o collections/UsuarioIterator.o collections/SalaIterator.o collections/ReservaIterator.o collections/PuntajeIterator.o collections/PeliculaIterator.o collections/List.o collections/FuncionIterator.o collections/ComentarioIterator.o collections/ColUsuarios.o collections/ColReservas.o collections/ColPeliculas.o collections/ColFunciones.o collections/ColCines.o collections/CineIterator.o collections/OrderedDictionaryEntry.o collections/OrderedDictionary.o collections/ListNode.o collections/ListIterator.o datatypes/sources/DtCine.o datatypes/sources/DtComentario.o datatypes/sources/DtFuncion.o datatypes/sources/DtPelicula.o datatypes/sources/DtPuntaje.o datatypes/sources/DtSala.o datatypes/sources/DtUsuario.o interfaces/ISistema.o interfaces/OrderedKey.o interfaces/IKey.o interfaces/IIterator.o interfaces/IDictionary.o interfaces/ICollection.o interfaces/ICollectible.o KeyInteger.o KeyString.o String.o
BIN      = LabPA
CXXFLAGS = $(CXXINCS) -std=c++11
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)

%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CPP) -c $< -o $@ $(CXXFLAGS)
cmake_minimum_required(VERSION 3.5)
project(lab_pa)

set(CMAKE_CXX_STANDARD 14)

include_directories(classes/headers)
include_directories(collections)
include_directories(datatypes/headers)
include_directories(interfaces)

add_executable(lab_pa
        classes/headers/cine.h
        classes/headers/funcion.h
        classes/headers/pelicula.h
        classes/headers/Reserva.h
        classes/headers/TarjetaDeCredito.h
        classes/headers/TarjetaDeDebito.h
        classes/headers/Usuario.h
        classes/sources/cine.cpp
        classes/sources/funcion.cpp
        classes/sources/Pelicula.cpp
        classes/sources/Reserva.cpp
        classes/sources/TarjetaDeCredito.cpp
        classes/sources/TarjetaDeDebito.cpp
        classes/sources/Usuario.cpp
        collections/ColReservas.h
        collections/ColResrevas.cpp
        collections/List.cpp
        collections/List.h
        collections/ListIterator.cpp
        collections/ListIterator.h
        collections/ListNode.cpp
        collections/ListNode.h
        collections/OrderedDictionary.cpp
        collections/OrderedDictionary.h
        collections/OrderedDictionaryEntry.cpp
        collections/OrderedDictionaryEntry.h
        datatypes/headers/DtCine.h
        datatypes/headers/DtFuncion.h
        datatypes/headers/DtPelicula.h
        datatypes/headers/DtUsuario.h
        datatypes/sources/DtCine.cpp
        datatypes/sources/DtFuncion.cpp
        datatypes/sources/DtPelicula.cpp
        datatypes/sources/DtUsuario.cpp
        interfaces/ICollectible.cpp
        interfaces/ICollectible.h
        interfaces/ICollection.cpp
        interfaces/ICollection.h
        interfaces/IDictionary.cpp
        interfaces/IDictionary.h
        interfaces/IIterator.cpp
        interfaces/IIterator.h
        interfaces/IKey.cpp
        interfaces/IKey.h
        interfaces/OrderedKey.cpp
        interfaces/OrderedKey.h
        main.cpp datatypes/headers/DtComentario.h datatypes/sources/DtComentario.cpp)


#ifndef CINE_H
#define CINE_H

class Cine {
public:
	Cine( int, string);
	int getIdCine();
	string getDireccion();
	funcion** getFunciones();
	int getcantFunciones();
	//DtCine getDatacine();
	void setIdCine( int idCine );
	void setDireccion( string Direccion);

private: 
	string Direccion;
	int IdCine;
	funcion ** Funciones;
	int cantFunciones;
};

#endif /* CINE_H */


#include <iostream>
#include <stdexcept>
#include "classes/headers/Sistema.h"
#include "datatypes/headers/DtUsuario.h"

using namespace std;

int main() {
	DtUsuario usuarioActual(/*Añadir un DtUsuario sacado de iniciar sesion*/);
	int op;

	//Menu de opciones
	//Opciones de administrador, como eliminar y demas, como un menu a parte

	//Switch de opciones
	//Agregar posibles errores con stdexcept en cada case
	try {
		switch (op)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
				// ...
			default:
				throw std::invalid_argument("La opcion ingresada no es correcta");
		}

	}
	catch (std::invalid_argument& e) {
		cout << "\nError: " << e.what() << endl;
	}
	cin.ignore();
	cout << "\nPresione ENTER para continuar...";
	cin.get();
	cout << endl;
}
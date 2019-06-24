#include <iostream>
#include <stdexcept>
#include "classes/headers/Sistema.h"
#include "datatypes/headers/DtUsuario.h"

using namespace std;

int main() {
	Sistema sistema = Sistema();
	//DtUsuario usuarioActual();
	int opInicio;
	int opMenu;
	int opAdmin;

	while (opInicio != 0) {
		//Menu Inicio de Sesion
		cout << "\tBienvenido, por favor inicie sesion" << endl;
		cout << "1 - Iniciar Sesion" << endl;
		cout << "2 - Registrarse" << endl;
		cout << "0 - Salir" << endl;
		cin >> opInicio;

		try {

			switch (opInicio)
			{
			case 0: 
				return 0;
				break;
			case 1: {
				string user, pass;
				cout << "Ingrese su nombre de usuario: ";
				cin >> user;
				cout << "Ingrese su contrasenia: ";
				cin >> pass;
				if (sistema.iniciarSesion(user, pass)) {
					//Usuario* u = sistema.usuarios.find(user)
					//DtUsuario usuarioActual(u->getNickName(), u->getImgPerfil(), u->getContrasenia());
					cout << "Ha iniciado sesion con exito" << endl;
				}
				else {
					cout << "No se logro iniciar sesion" << endl;
				}
			}
			case 2: {
				string user, img, pass;
				cout << "Ingrese su nombre de usuario: ";
				cin >> user;
				cout << "Ingrese su contrasenia: ";
				cin >> pass;
				sistema.usuarios.add(new Usuario(user, img, pass));
				DtUsuario usuarioActual(user, img, pass);
				break;
			}
			default:
				throw std::invalid_argument("La opcion ingresada no es correcta");
			}

			while (opMenu != 0) {
				//Menu de opciones
				cout << "\tMenu" << endl;
				cout << "1 - Hacer una reserva" << endl;
				cout << "2 - Mostrar el catalogo de peliculas" << endl;
				cout << "3 - Ver la informacion de una pelicula" << endl;
				//cout << "4 - Puntuar una Pelicula" << endl;
				//cout << "5 - Comentar pelicula" << endl;
				//cout << "6 - Ver comentarios y puntajes" << endl;
				cout << "4 - Opciones Administrativas" << endl;
				cout << "0 - Salir" << endl;

				//Switch de opciones
				//Agregar posibles errores con stdexcept en cada case

				switch (opMenu)
				{
				case 0: {
					while (opAdmin != 0) {
						//Menu Admin.
						cout << "1 - Alta Cine" << endl;
						cout << "2 - Alta Pelicula" << endl;
						cout << "3 - Alta Funcion" << endl;
						cout << "4 - Eliminar Pelicula" << endl;
						cout << "0 - Salir" << endl;
						cin >> opAdmin;
						
						switch (opAdmin) {
						case 1:
							break;
						case 2:
							break;
						case 3: 
							break;
						case 4:
							break;
						}
					}
					break;
				}
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

		}
		catch (std::invalid_argument& e) {
			cout << "\nError: " << e.what() << endl;
		}
		cin.ignore();
		cout << "\nPresione ENTER para continuar...";
		cin.get();
		cout << endl;

	}
}
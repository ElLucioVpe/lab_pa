#include <iostream>
#include <stdexcept>
#include "classes/headers/Sistema.h"
#include "datatypes/headers/DtUsuario.h"

using namespace std;

void DatosTesteo();

int main() {
	ISistema* sistema = Sistema::getInstance();
	DatosTesteo();
	//DtUsuario usuarioActual();
	int op;

	while (true) {
		//Menu Inicio de Sesion
		cout << "\tBienvenido, por favor inicie sesion\n" << endl;
		cout << "1 - Iniciar Sesion" << endl;
		cout << "2 - Registrarse" << endl;
		cout << "0 - Salir" << endl;
		cin >> op;

		try {

			switch (op) {
				case 0:
					return 0;
					break;
				case 1: {
					string user, pass;
					cout << "Ingrese su nombre de usuario: ";
					cin >> user;
					cout << "Ingrese su contrasenia: ";
					cin >> pass;
					if (sistema->iniciarSesion(user, pass)) {
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
					cout << "Agregue una imagen de perfil (URL): ";
					cin >> img;
					//sistema->usuarios->add(new Usuario(user, img, pass));
					DtUsuario usuarioActual(user, img, pass);
					break;
				}
				default:
					throw std::invalid_argument("La opcion ingresada no es valida");
			}

			while (op != 0) {
				//Menu de opciones
				cout << "\n\tMenu\n" << endl;
				cout << "1 - Hacer una reserva" << endl;
				cout << "2 - Mostrar el catalogo de peliculas" << endl;
				cout << "3 - Ver la informacion de una pelicula" << endl;
				//cout << "4 - Puntuar una Pelicula" << endl;
				//cout << "5 - Comentar pelicula" << endl;
				//cout << "6 - Ver comentarios y puntajes" << endl;
				cout << "4 - Opciones Administrativas" << endl;
				cout << "0 - Cerrar Sesion" << endl;
				cin >> op;

				//Switch de opciones
				//Agregar posibles errores con stdexcept en cada case

				switch (op)
				{
					case 0:
						break;
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
						// ...
					case 4: {
						while (op != 0) {
							//Menu Admin.
							cout << "\n\tMenu de Administracion\n" << endl;
							cout << "1 - Alta Cine" << endl;
							cout << "2 - Alta Pelicula" << endl;
							cout << "3 - Alta Funcion" << endl;
							cout << "4 - Eliminar Pelicula" << endl;
							cout << "0 - Volver al menu anterior" << endl;
							cin >> op;

							switch (op) {
							case 0:
								break;
							case 1:
								break;
							case 2:
								break;
							case 3:
								break;
							case 4:
								break;
							default:
								throw std::invalid_argument("La opcion ingresada no es valida");
							}
							
							if (op != 0) {
								cin.ignore();
								cout << "\nPresione ENTER para continuar...";
								cin.get();
								cout << endl;
							}				
						}
						op = -1;
						break;
					}
					default:
						throw std::invalid_argument("La opcion ingresada no es valida");
				}
			}

		}
		catch (std::invalid_argument& e) {
			cout << "\nError: " << e.what() << endl;
		}
		
		if (op != 0) {
			cin.ignore();
			cout << "\nPresione ENTER para continuar...";
			cin.get();
			cout << endl;
		}
	}
}

void DatosTesteo() {

}
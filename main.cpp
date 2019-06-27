#include <iostream>
#include <stdexcept>
#include "classes/headers/Sistema.h"
#include "datatypes/headers/DtUsuario.h"

using namespace std;

//Encabezados de funciones auxiliares
void DatosTesteo();
bool DeseaContinuar(string msg);
void OpcionCrearReserva(DtUsuario* usuarioActual);
void OpcionVerInfoPelicula();
void OpcionPuntuarPelicula();
void OpcionComentarPelicula();
void OpcionVerComentariosyPuntajes();
void OpcionesAdministrativas();

int main() {
	ISistema* sistema = Sistema::getInstance();
	DtUsuario* usuarioActual = NULL;
	DatosTesteo();

	while (true) {
		int op;
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
					getline(cin, user);
					cout << "Ingrese su contrasenia: ";
					cin >> pass;
					if (sistema->iniciarSesion(user, pass)) { //iniciar sesion a DtUsuario seria mejor en vez de bool
						//usuarioActual = sistema->iniciarSesion(user, pass);
						cout << "Ha iniciado sesion con exito" << endl;
					}
					else {
						cout << "No se logro iniciar sesion" << endl;
					}
					break;
				}	
				case 2: {
					string user, img, pass;
					cout << "Ingrese su nombre de usuario: ";
					cin.ignore();
					getline(cin, user);
					cout << "Ingrese su contrasenia: ";
					cin >> pass;
					cout << "Agregue una imagen de perfil (URL): ";
					cin >> img;
					sistema->AltaUsuario(user, img, pass);
					usuarioActual = new DtUsuario(user, img, pass);
					break;
				}
				default:
					throw std::invalid_argument("La opcion ingresada no es valida");
			}

		}
		catch (std::invalid_argument& e) {
			cout << "\nError: " << e.what() << endl;
		}

		

		while (op != 0) {
			//Menu de opciones
			cout << "\n\tMenu\n" << endl;
			cout << "1 - Hacer una reserva" << endl;
			cout << "2 - Ver la informacion de una pelicula" << endl;
			cout << "3 - Puntuar una Pelicula" << endl;
			cout << "4 - Comentar pelicula" << endl;
			cout << "5 - Ver comentarios y puntajes" << endl;
			cout << "6 - Opciones Administrativas" << endl;
			cout << "0 - Cerrar Sesion" << endl;
			cin >> op;

			//Switch de opciones
			//Agregar posibles errores con stdexcept en cada case
			try {

				switch (op)
				{
					case 0:
						break;
					case 1:
						OpcionCrearReserva(usuarioActual);
						break;
					case 2:
						OpcionVerInfoPelicula();
						break;
					case 3:
						OpcionPuntuarPelicula();
						break;
					case 4:
						OpcionComentarPelicula();
						break;
					case 5:
						OpcionVerComentariosyPuntajes();
						break;
					case 6:
						OpcionesAdministrativas();
						break;
					default:
						throw std::invalid_argument("La opcion ingresada no es valida");
				}

			}
			catch (std::invalid_argument& e) {
				cout << "\nError: " << e.what() << endl;
			}

			if (op != 0) {
				//cin.ignore();
				cout << "\nPresione ENTER para continuar...";
				cin.get();
				cout << endl;
			}
		}
	}
}


//Funciones auxiliares
void DatosTesteo() {
	ISistema* s = Sistema::getInstance();
	s->AltaUsuario("user1", "www.perfiles.com/user1.jpg", "contra1");
	s->AltaUsuario("user2", "www.perfiles.com/user2.jpg", "contra2");
	s->AltaUsuario("user3", "www.perfiles.com/user3.jpg", "contra3");

	s->AltaPelicula("Avengers: Endgame", "www.posters.com/endgame.jpg", "Thanos 2");
	s->AltaPelicula("Avengers: Endgame (Reestreno)", "www.posters.com/endgame2.jpg", "Thanos 2 2");
	s->AltaPelicula("Jhon Whick 1", "www.posters.com/jw1.jpg", "Primera entrega de la saga de Jhon Whick tu asesino favorito");
	s->AltaPelicula("Jhon Whick 2", "www.posters.com/jw2.jpg", "Segunda entrega de la saga de Jhon Whick tu asesino favorito");
	s->AltaPelicula("Jhon Whick 3", "www.posters.com/jw3.jpg", "Tercera entrega de la saga de Jhon Whick tu asesino favorito");
	
	s->AltaCine(1, "Calle 1 Nro. 1");
	s->AltaCine(2, "Calle 2 Nro. 2");
	s->AltaCine(3, "Calle 3 Nro. 3");
	s->AltaCine(4, "Calle 4 Nro. 4");
}

bool DeseaContinuar(string msg) {
	string elegir;

	while (true) {
		cout << endl;
		cout << msg;
		cin >> elegir;
		cout << endl;

		if (elegir == "Si" || elegir == "si") {
			//El usuario continuara con lo que sea este despues de esta funcion
			return true;
		}
		else {
			if (elegir == "No" || elegir == "no") {
				//El usuario saldra de la operacion actual
				cout << "Se cancela la operacion" << endl;
				return false;
			}
			else {
				//El usuario seguira en el loop hasta dar una opcion valida
				cout << "Error: La opcion ingresada no es valida" << endl;
			}
		}
	}
}

void OpcionCrearReserva(DtUsuario* usuarioActual) {
	ISistema* sistema = Sistema::getInstance(); //Obtengo la instancia de Sistema

	string titulo, elegir, banco = "", financiera = "";
	int cantAsientos, idFuncion, idCine;
	float costo;

	cout << "\n\tCatalogo de Peliculas" << endl << endl;
	ICollection* t = sistema->ListarTitulos();
	IIterator* it = t->getIterator();
	while (it->hasCurrent()) {
		cout << dynamic_cast<KeyString*>(it->getCurrent())->getValue() << endl;
		it->next();
	}

	if (DeseaContinuar("Continuar con la reserva? (Si/No): ") == false) return;

	cout << "Ingrese el titulo de la pelicula que desee: ";
	cin.ignore();
	getline(cin, titulo);

	sistema->VerInfoPelicula(titulo);

	if (DeseaContinuar("Desea ver informacion adicional? (Si/No): ") == false) return;
	
	ICollection* c = sistema->ListarCinesPorTitulo(titulo);
	it = c->getIterator();
	while (it->hasCurrent()) {
		DtCine* c = dynamic_cast<DtCine*>(it->getCurrent());
		cout << "Cine " + c->getIdCine() << endl; 
		cout << "Direccion :"+c->getDireccion() << endl;
		it->next();
	}

	if (DeseaContinuar("Desea elegir un cine? (Si/No): ") == false) return;
	
	cout << "Ingrese el numero del cine que desee: ";
	cin >> idCine;

	ICollection* f = sistema->ListarFunciones(idCine, titulo);
	it = f->getIterator();
	while (it->hasCurrent()) {
		DtFuncion* f = dynamic_cast<DtFuncion*>(it->getCurrent());
		cout << "Funcion " + f->getIdFuncion() << endl;
		cout << "Horario :" + f->getHorario() << endl;
		it->next();
	}

	if (DeseaContinuar("Desea elegir una funcion? (Si/No)") == false) return;
	cout << "Elija una funcion: ";
	cin >> idFuncion;

	cout << "Ingrese la cantidad de asientos que desea reservar: ";
	cin >> cantAsientos;

	costo = (float)(cantAsientos * 299.99);

	cout << "Elija su tipo de pago (Debito/Credito): ";
	cin >> elegir;

	while (elegir != "Debito" && elegir != "Credito")
	{
		if (elegir == "Debito") {
			cout << "Ingrese su banco: ";
			cin >> banco;
		}
		else {
			if (elegir == "Credito") {
				cout << "Ingrese su financiera: ";
				cin >> financiera;

			}
			else cout << "Error: La opcion ingresada no es valida";
		}
	}
	
	cout << "Usted pagara: ";
	cout << costo << endl;
	if (DeseaContinuar("Continuar con la reserva? (Si/No): ") == false) return;
	sistema->CrearReserva(cantAsientos, costo, titulo, idFuncion, usuarioActual->getNickName(), banco, financiera);
}

void OpcionVerInfoPelicula()
{
}

void OpcionPuntuarPelicula()
{
}

void OpcionComentarPelicula()
{
}

void OpcionVerComentariosyPuntajes()
{
}

void OpcionesAdministrativas() {
	ISistema* s = Sistema::getInstance();
	int op = -1;

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
			s->AltaCine(0, "ejemplo");
			break;
		case 2:
			s->AltaPelicula("ejemplo", "ejemplo", "ejemplo");
			break;
		case 3:
		//Luigi
		//Films
		cout << "\n\tCatalogo de Peliculas" << endl << endl;
		ICollection* t = sistema->ListarTitulos();
		IIterator* it = t->getIterator();
		while (it->hasCurrent()) {
			cout << dynamic_cast<KeyString*>(it->getCurrent())->getValue() << endl;
			it->next();
		}



		//Cines
		ICollection* c = sistema->ListarCinesPorTitulo(titulo);
		it = c->getIterator();

		while (it->hasCurrent()) {
			DtCine* c = dynamic_cast<DtCine*>(it->getCurrent());
			cout << "Cine " + c->getIdCine() << endl; 
			cout << "Direccion :"+c->getDireccion() << endl;
			it->next();
		}


			s->AltaFuncion();
			break;
		case 4: {
			string t;
			cout << "Ingrese el titulo de la pelicula a eliminar: ";
			cin >> t;
			s->EliminarPelicula(t);
			break;
		}
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
}
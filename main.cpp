#include <iostream>
#include <stdexcept>
#include <vector>
#include "classes/headers/Sistema.h"
#include "datatypes/headers/DtUsuario.h"

using namespace std;

//Encabezados de funciones auxiliares
void DatosTesteo();
bool DeseaContinuar(string msg);
void OpcionCrearReserva(DtUsuario* usuarioActual);
void OpcionVerInfoPelicula();
void OpcionPuntuarPelicula(DtUsuario* usuarioActual);
void OpcionComentarPelicula();
void OpcionVerComentariosyPuntajes();
void OpcionesAdministrativas();
void OpcionAltaCine();
void OpcionAltaPelicula();
void OpcionAltaFuncion();
void OpcionEliminarPelicula();

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

					if (sistema->iniciarSesion(user, pass)) {
						usuarioActual = sistema->iniciarSesion(user, pass);
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
					sistema->AltaUsuario(user, img, pass, false);
					usuarioActual = new DtUsuario(user, img, pass, false);
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
						OpcionPuntuarPelicula(usuarioActual);
						break;
					case 4:
						OpcionComentarPelicula();
						break;
					case 5:
						OpcionVerComentariosyPuntajes();
						break;
					case 6:
						if (usuarioActual->getAdmin()) OpcionesAdministrativas();
						else throw std::invalid_argument("No tiene permitido el acceso");
						
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
	s->AltaUsuario("admin", "www.perfiles.com/admin.jpg", "admin123", true);
	s->AltaUsuario("user1", "www.perfiles.com/user1.jpg", "contra1", false);
	s->AltaUsuario("user2", "www.perfiles.com/user2.jpg", "contra2", false);
	s->AltaUsuario("user3", "www.perfiles.com/user3.jpg", "contra3", false);

	s->AltaPelicula("Avengers: Endgame", "www.posters.com/endgame.jpg", "Thanos 2");
	s->AltaPelicula("Avengers: Endgame (Reestreno)", "www.posters.com/endgame2.jpg", "Thanos 2 2");
	s->AltaPelicula("Jhon Whick 1", "www.posters.com/jw1.jpg", "Primera entrega de la saga de Jhon Whick, tu asesino favorito");
	s->AltaPelicula("Jhon Whick 2", "www.posters.com/jw2.jpg", "Segunda entrega de la saga de Jhon Whick, tu asesino favorito");
	s->AltaPelicula("Jhon Whick 3", "www.posters.com/jw3.jpg", "Tercera entrega de la saga de Jhon Whick, tu asesino favorito");
	
	s->AltaCine("Calle 1 Nro. 1");
	s->AltaCine("Calle 2 Nro. 2");
	s->AltaCine("Calle 3 Nro. 3");
	s->AltaCine("Calle 4 Nro. 4");
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
		time_t h = f->getHorario();
		cout << "Horario :" << ctime(&h) << endl;
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
	
	cout << "Usted pagara: " << costo << endl;
	if (DeseaContinuar("Continuar con la reserva? (Si/No): ") == false) return;
	sistema->CrearReserva(cantAsientos, costo, titulo, idFuncion, usuarioActual->getNickName(), banco, financiera);
}

void OpcionVerInfoPelicula()
{
	ISistema* s = Sistema::getInstance();
	string titulo;

	cout << "\n\tCatalogo de Peliculas" << endl << endl;
	ICollection* t = s->ListarTitulos();
	IIterator* it = t->getIterator();
	while (it->hasCurrent()) {
		cout << dynamic_cast<KeyString*>(it->getCurrent())->getValue() << endl;
		it->next();
	}

	if (DeseaContinuar("Desea seleccionar una pelicula? (Si/No): ") == false) return;

	cout << "Ingrese el titulo de la pelicula que desee: ";
	cin.ignore();
	getline(cin, titulo);

	s->VerInfoPelicula(titulo);
}

void OpcionPuntuarPelicula(DtUsuario* usuarioActual) {
    ISistema* sistema = Sistema::getInstance();

    string _nombre;
    int _puntuacion;

	//Listar peliculas primero
    cout << "Nombre de pelicula: " << endl;
    cin >> _nombre;

    cout << "Puntuacion (1/5): " << endl;
    cin >> _puntuacion;

    if(_puntuacion < 1 || _puntuacion > 5) {
        cout << "Puntuacion incorrecta." << endl;
    } else {
		//Esto ya deberia ser dentro de sistema, sino no puedes obtener la pelicula

        ICollection* _peliculas = sistema->ListarFunciones();
        IIterator* _iterator = _peliculas->getIterator();
		//Una funcion auxiliar sistema->getUsuario(); podria ayudar
        while (_iterator->hasCurrent()) {
            Pelicula* p = dynamic_cast<Pelicula*>(_iterator->getCurrent());

            if(p->getTitulo() == _nombre) {
                p->puntuarPelicula(_puntuacion, usuarioActual);
            }

            _iterator->next();
        }
    }
}

void OpcionComentarPelicula()
{
   ISistema* sistema = Sistema::getInstance();

   string _nombre;
   string _comentario;

   cout << "Nombre de pelicula: " << endl;
   cin >> _nombre;

   cout << "Comentario: " << endl;
   cin >> _comentario;

   ICollection* _peliculas = sistema->ListarFunciones();
   IIterator* _iterator = _peliculas->getIterator();

   while (_iterator->hasCurrent()) {
      Pelicula* p = dynamic_cast<Pelicula*>(_iterator->getCurrent());

      if(p->getTitulo() == _nombre) {
         p->agregarComentario(_comentario);
      }

      _iterator->next();
   }
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
			OpcionAltaCine();
			break;
		case 2: {
			OpcionAltaPelicula();
			break;
		}
		case 3:
			OpcionAltaFuncion();
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

void OpcionAltaCine() {
	ISistema* s = Sistema::getInstance();

	string dir;
	int cantaux, idCine;
	vector<int> cantAsientos;

	cout << "Ingrese la direccion del cine: ";
	cin.ignore();
	getline(cin, dir);

	while (DeseaContinuar("Desea ingresar una sala? (Si/No): ")) {
		cout << "Ingrese la capacidad de la sala: ";
		cin >> cantaux;
		cantAsientos.push_back(cantaux);
	}

	if (DeseaContinuar("Desea completar la operacion? (Si/No): ") == false) return;
	s->AltaCine(dir);
	idCine = s->DarUltimoCine();

	for (auto i = cantAsientos.begin(); i != cantAsientos.end(); i++) {
		s->AltaSala(idCine, *i);
	}
}

void OpcionAltaPelicula()
{
	ISistema* s = Sistema::getInstance();
	string titulo, img, sinopsis;

	cin.ignore();
	getline(cin, titulo);


	cin.ignore();
	getline(cin, img);

	cin.ignore();
	getline(cin, sinopsis);
	s->AltaPelicula(titulo, img, sinopsis);
}


void OpcionAltaFuncion(){
	ISistema* sistema = Sistema::getInstance(); //Obtengo la instancia de Sistema
	string titulo, fechaFun;


	//Lista Films
	cout << "\n\tCatalogo de Peliculas" << endl << endl;
	ICollection* t = sistema->ListarTitulos();
	IIterator* it = t->getIterator();
	while (it->hasCurrent()) {
		cout << dynamic_cast<KeyString*>(it->getCurrent())->getValue() << endl;
		it->next();
	}

	//Selecciona Films
	cout << "Ingrese el titulo de la pelicula que desee: ";
	cin.ignore();
	getline(cin, titulo);


	//Listar Cines
	ICollection* c = sistema->ListarCines();
	it = c->getIterator();
	while (it->hasCurrent()) {
		DtCine* c = dynamic_cast<DtCine*>(it->getCurrent());
		cout << "Cine " + c->getIdCine() << endl; 
		cout << "Direccion :"+c->getDireccion() << endl;
		it->next();
	}
	
	//Selecciona Cine
	int idCine;
	cout << "Ingrese el numero del cine que desee: ";
	cin >> idCine;


	cout << "Ingrese Fecha y hora de la funcion: ";
	cin >> fechaFun;

	//Conversion de string a time_t
	time_t horario;
	int yy, month, dd, hh, mm, ss;
	struct tm horariotm = { 0 };

	sscanf(fechaFun.c_str(), "%d/%d/%d %d:%d:%d", &yy, &month, &dd, &hh, &mm, &ss);
	horariotm.tm_year = yy - 1900;
	horariotm.tm_mon = month - 1;
	horariotm.tm_mday = dd;
	horariotm.tm_hour = hh;
	horariotm.tm_min = mm;
	horariotm.tm_sec = ss;
	horariotm.tm_isdst = -1;

	horario = mktime(&horariotm);
	//
	vector<int> SalasOcupadas;


	//Lista Salas - Mostrar Ocupadas y Disponibles
	//Voy por todas las pelis
	ICollection* t = sistema->ListarTitulos();
	IIterator* it = t->getIterator();

	
	while (it->hasCurrent()) {

		//Voy por todas las funciones de todas las pelis de el cine seleccionado por el user
		ICollection* f = sistema->ListarFunciones(idCine, dynamic_cast<KeyString*>(it->getCurrent())->getValue());
		IIterator* it2 = f->getIterator();

		while (it2->hasCurrent()) {

			DtFuncion* f = dynamic_cast<DtFuncion*>(it->getCurrent());
			
			time_t h = f->getHorario();
			//Me fijo si dicha funcion + 3 horas esta en el rango de la hora y fecha que el user puso
			//No me salio ese if xD
			if(horario<h+3){
			//En el caso de ser asi, es porque esta ocupada esa sala entonces la pusheo dentro del vector dinamico
				SalasOcupadas.push_back(f->getIdSala()); //Crear getIdSala

			}

			it2->next();

		}


		it->next();
	}

	//Mostramos las salas

	ICollection* s = sistema->ListarSalas(idCine);
	it = s->getIterator();
	while (it->hasCurrent()) {
		DtSala* s = dynamic_cast<DtSala*>(it->getCurrent());
		cout << "IdSala " + s->getIdSala() << endl; 
		cout << "cantAsientos :"+s->getCantAsientos() << endl;
		//Comparamos si esta en la lista de no disponibles para este cine a esa hora
		if(std::find(SalasOcupadas.begin(), SalasOcupadas.end(), s->getIdSala) != SalasOcupadas.end()) {
			cout << "Ocupada" << endl;
		} else {
			cout << "Disponible" << endl;
		}
			it->next();
	}


	//Selecionar Sala
	int idSala;
	cout << "Ingrese el numero de sala que desee: ";
	cin >> idSala;

	//Crear Reserva
		if(std::find(SalasOcupadas.begin(), SalasOcupadas.end(), idSala) != SalasOcupadas.end()) {
			cout << "Esta Seleccionando una sala que esta ocupada" << endl;
		} else {
	 		sistema->AltaFuncion(titulo,fechaFun,idCine,idSala);
		}
}

void OpcionEliminarPelicula()
{
}

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm> //Inlcude necesario en dev-c++s
#include <vector>
#include <algorithm>
#include "classes/headers/Sistema.h"
#include "datatypes/headers/DtUsuario.h"

using namespace std;

//Encabezados de funciones auxiliares
void DatosTesteo();
bool DeseaContinuar(string msg);
void OpcionCrearReserva(DtUsuario* usuarioActual);
void OpcionVerInfoPelicula();
void OpcionPuntuarPelicula(DtUsuario* usuarioActual);
void OpcionComentarPelicula(DtUsuario* usuarioActual);
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
					cin.ignore();
					getline(cin, user);
					cout << "Ingrese su contrasenia: ";
					getline(cin, pass);

					usuarioActual = sistema->iniciarSesion(user, pass);
					cout << "\nHa iniciado sesion con exito" << endl;
					break;
				}	
				case 2: {
					string user, img, pass;
					cout << "Ingrese su nombre de usuario: ";
					cin.ignore();
					getline(cin, user);
					cout << "Ingrese su contrasenia: ";
					getline(cin, pass);
					cout << "Agregue una imagen de perfil (URL): ";
					getline(cin, img);

					sistema->AltaUsuario(user, img, pass, false);
					//usuarioActual = new DtUsuario(user, img, pass, false);
					break;
				}
				default:
					throw std::invalid_argument("La opcion ingresada no es valida");
			}

		}
		catch (std::invalid_argument& e) {
			cout << "\nError: " << e.what() << endl;
		}

		if (usuarioActual != NULL) //Prohibe la entrada sin iniciar sesion
		{
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
						usuarioActual = NULL;
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
						OpcionComentarPelicula(usuarioActual);
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
}


//Funciones auxiliares
void DatosTesteo() {
	ISistema* s = Sistema::getInstance();

	//Usuarios
	s->AltaUsuario("admin", "www.perfiles.com/admin.jpg", "admin123", true);
	s->AltaUsuario("user1", "www.perfiles.com/user1.jpg", "contra1", false);
	s->AltaUsuario("user2", "www.perfiles.com/user2.jpg", "contra2", false);
	s->AltaUsuario("user3", "www.perfiles.com/user3.jpg", "contra3", false);

	//Peliculas
	s->AltaPelicula("Avengers: Endgame", "www.posters.com/endgame.jpg", "Thanos 2");
	s->AltaPelicula("Jhon Whick 1", "www.posters.com/jw1.jpg", "Primera entrega de la saga de Jhon Whick, tu asesino favorito");
	s->AltaPelicula("Jhon Whick 2", "www.posters.com/jw2.jpg", "Segunda entrega de la saga de Jhon Whick, tu asesino favorito");
	s->AltaPelicula("Jhon Whick 3", "www.posters.com/jw3.jpg", "Tercera entrega de la saga de Jhon Whick, tu asesino favorito");
	
	//Puntajes
	s->AltaPuntaje(5, "Avengers: Endgame", "user1");
	s->AltaPuntaje(3, "Avengers: Endgame", "user2");
	s->AltaPuntaje(4, "Avengers: Endgame", "user3");
	s->AltaPuntaje(1, "Jhon Whick 3", "user1");
	s->AltaPuntaje(5, "Jhon Whick 3", "admin");
	s->AltaPuntaje(4, "Jhon Whick 3", "user1"); //Solo modifica no crea otra
	s->AltaPuntaje(5, "Jhon Whick 3", "user3"); 

	//Comentarios
	vector<int> padresComentarios;
	s->AltaComentario(padresComentarios, "10/10", "Avengers: Endgame", "user1");
	s->AltaComentario(padresComentarios, "10/10 x2", "Avengers: Endgame", "user1");
	s->AltaComentario(padresComentarios, "Yo hice la pusieran en el cine by El Admin", "Jhon Whick 3", "admin");
	s->AltaComentario(padresComentarios, "Ni la vi", "Jhon Whick 3", "user2");

	//Respuestas de comentarios
	padresComentarios.push_back(1);
	s->AltaComentario(padresComentarios, "Gracias admin", "Jhon Whick 3", "user1");
	padresComentarios.push_back(1);
	s->AltaComentario(padresComentarios, "Denada user1, me voy a asegurar este la 4", "Jhon Whick 3", "admin");

	//Cines
	s->AltaCine("Calle 1 Nro. 1");
	s->AltaCine("Calle 2 Nro. 2");
	s->AltaCine("Calle 3 Nro. 3");

	//Salas
	s->AltaSala(1, 100);
	s->AltaSala(1, 150);
	s->AltaSala(1, 50);
	s->AltaSala(2, 100);
	s->AltaSala(2, 100);
	s->AltaSala(3, 200);

	//Funciones que no deberian verse
	s->AltaFuncion("Avengers: Endgame", "2019/06/10 18:30:00", 1, 1);
	s->AltaFuncion("Jhon Whick 1", "2019/06/12 18:30:00", 2, 1);
	s->AltaFuncion("Jhon Whick 2", "2019/06/12 20:30:00", 2, 2);
	s->AltaFuncion("Jhon Whick 3", "2019/06/12 22:30:00", 2, 1);

	//Funciones que deberian verse
	s->AltaFuncion("Avengers: Endgame", "2019/07/12 19:30:00", 1, 1);
	s->AltaFuncion("Jhon Whick 1", "2019/07/10 18:30:00", 1, 3);
	s->AltaFuncion("Jhon Whick 2", "2019/07/10 20:30:00", 2, 2);
	s->AltaFuncion("Jhon Whick 3", "2019/07/10 22:30:00", 3, 1);
	s->AltaFuncion("Jhon Whick 3", "2019/07/11 19:30:00", 1, 3);
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
	int cantAsientos, idFuncion, idCine, descuento = 0;
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
		cout << "Cine " + std::to_string(c->getIdCine()) << endl;
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
		cout << "Funcion " + std::to_string(f->getIdFuncion()) << endl;
		time_t h = f->getHorario();
		cout << "Horario :" << ctime(&h) << endl;
		it->next();
	}

	if (DeseaContinuar("Desea elegir una funcion? (Si/No)") == false) return;
	cout << "Elija una funcion: ";
	cin >> idFuncion;

	cout << "Ingrese la cantidad de asientos que desea reservar: ";
	cin >> cantAsientos;

	cout << "Elija su tipo de pago (Debito/Credito): ";
	cin >> elegir;

	while (elegir != "Debito" && elegir != "Credito")
	{
		if (elegir == "Debito") {
			cout << "Ingrese su banco: ";
			cin.ignore();
			getline(cin, banco);
		}
		else {
			if (elegir == "Credito") {
				cout << "Ingrese su financiera: ";
				cin.ignore();
				getline(cin, financiera);
				descuento = sistema->ObtenerDescuentoFinanciera(financiera);
				if (descuento != 0) cout << "Descuento por financiera: " << std::to_string(descuento) << "%" << endl;
			}
			else cout << "Error: La opcion ingresada no es valida";
		}
	}
	
	costo = (float)(cantAsientos * 299.99);
	costo -= (costo * (descuento/100));
	cout << "Usted pagara: " << std::to_string(costo) << endl;
	if (DeseaContinuar("Continuar con la reserva? (Si/No): ") == false) return;
	sistema->CrearReserva(cantAsientos, costo, titulo, idFuncion, usuarioActual->getNickName(), banco, financiera);
}

void OpcionVerInfoPelicula()
{
	ISistema* sistema = Sistema::getInstance();

	string titulo;
	int idCine;
	bool seguir = true;

	while (seguir) {
		cout << "\n\tCatalogo de Peliculas" << endl << endl;
		ICollection* t = sistema->ListarTitulos();
		IIterator* it = t->getIterator();
		while (it->hasCurrent()) {
			cout << dynamic_cast<KeyString*>(it->getCurrent())->getValue() << endl;
			it->next();
		}

		if (DeseaContinuar("Desea seleccionar una pelicula? (Si/No): ") == false) return;

		cout << "Ingrese el titulo de la pelicula que desee: ";
		cin.ignore();
		getline(cin, titulo);

		sistema->VerInfoPelicula(titulo);

		if (DeseaContinuar("Desea ver informacion adicional? (Si/No): ") == false) return;

		ICollection* c = sistema->ListarCinesPorTitulo(titulo);
		it = c->getIterator();
		while (it->hasCurrent()) {
			DtCine* c = dynamic_cast<DtCine*>(it->getCurrent());
			cout << "Cine " + std::to_string(c->getIdCine()) << endl;
			cout << "Direccion :" + c->getDireccion() << endl;
			it->next();
		}

		if (DeseaContinuar("Desea elegir un cine? (Si/No): ") == false) return;

		cout << "Ingrese el numero del cine que desee: ";
		cin >> idCine;

		ICollection* f = sistema->ListarFunciones(idCine, titulo);
		it = f->getIterator();
		while (it->hasCurrent()) {
			DtFuncion* f = dynamic_cast<DtFuncion*>(it->getCurrent());
			cout << "Funcion " + std::to_string(f->getIdFuncion()) << endl;
			time_t h = f->getHorario();
			cout << "Horario :" << ctime(&h) << endl;
			it->next();
		}

		seguir = DeseaContinuar("Desea ver informacion de otra pelicula? (Si/No): ");
	}
}

void OpcionPuntuarPelicula(DtUsuario* usuarioActual) {
    ISistema* sistema = Sistema::getInstance();

    string _nombre;

	cout << "\n\tCatalogo de Peliculas" << endl << endl;
	ICollection* t = sistema->ListarTitulos();
	IIterator* it = t->getIterator();
	while (it->hasCurrent()) {
		cout << dynamic_cast<KeyString*>(it->getCurrent())->getValue() << endl;
		it->next();
	}

	if (DeseaContinuar("Desea seleccionar una pelicula? (Si/No): ") == false) return;

    cout << "Ingrese el nombre de pelicula: " << endl;
    cin >> _nombre;

	int puntajeAnterior = sistema->YaPuntuo(_nombre, usuarioActual->getNickName());
	int _puntuacion;

	if (puntajeAnterior = 0) {
		cout << "Puntuacion Anterior: " << std::to_string(puntajeAnterior) << endl << endl;
		cout << "Desea modificarla? (Si/No): ";
		string elegir;
		bool seguir = true;

		while (seguir) {
			cin >> elegir;
			if (elegir == "Si" || elegir == "si") {
				seguir = false;
			}
			else {
				if (elegir == "No" || elegir == "no") {
					cout << "Se cancela la operacion" << endl;
					return;
				}
				else {
					cout << "Error: La opcion ingresada no es valida" << endl;
				}
			}
		}
	}

	cout << "Puntuacion (1/5): " << endl;
	cin >> _puntuacion;

	if (_puntuacion < 1 || _puntuacion > 5) throw std::invalid_argument("Puntuacion incorrecta.");

	sistema->AltaPuntaje(_puntuacion, _nombre, usuarioActual->getNickName());
}

void OpcionComentarPelicula(DtUsuario* usuarioActual)
{
   ISistema* sistema = Sistema::getInstance();

   string _nombre;
   string _comentario;
   vector<int> padres;

   //cout << "probando xd" << padres.size() << endl;

   cout << "Ingrese el nombre de una pelicula: " << endl;
   cin.ignore();
   getline(cin, _nombre);

   //Listar comentarios de la pelicula
   cout << "Comentarios:" << endl;
   sistema->ListarComentarios(_nombre);

   while (DeseaContinuar("Desea ingresar un comentario? (Si/No): "))
   {
	   if(DeseaContinuar("Desea comentar un comentario ya existente? (Si/No): ")) {
		   int id_comentario;
		   bool seguir = true;

		   while (seguir) {
			   cout << "Ingrese la id del comentario que desea responder \n(Si es respuesta de otro, ingrese primero la id de ese): ";
			   cin >> id_comentario;
			   padres.push_back(id_comentario);

			   seguir = DeseaContinuar("Desea ingresar otra id (Si/No): ");
		   }

		   cout << "Ingrese su comentario: " << endl;
		   cin.ignore();
		   getline(cin, _comentario);
	   }
	   else {
		   cout << "Ingrese su comentario: " << endl;
		   cin.ignore();
		   getline(cin, _comentario);
		   //padres.push_back(0);
	   }
   }

   sistema->AltaComentario(padres, _comentario, _nombre, usuarioActual->getNickName()); //agregar parametro int padre, si no es respuesta padre = 0
}

void OpcionVerComentariosyPuntajes()
{
    ISistema* sistema = Sistema::getInstance(); //Obtengo la instancia de Sistema

	string titulo;

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

    sistema->VerInfoPelicula(titulo);
	cout << endl;
    sistema->VerComentariosyPuntajes(titulo);
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
		case 2:
			OpcionAltaPelicula();
			break;
		case 3:
			OpcionAltaFuncion();
			break;
		case 4:
			OpcionEliminarPelicula();
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

	cout << "Ingrese el titulo: ";
	cin.ignore();
	getline(cin, titulo);

	cout << "Ingrese el url del poster: ";
	cin.ignore();
	getline(cin, img);

	cout << "Ingrese la sinopsis: ";
	cin.ignore();
	getline(cin, sinopsis);

	s->AltaPelicula(titulo, img, sinopsis);
}


void OpcionAltaFuncion(){
	ISistema* sistema = Sistema::getInstance(); //Obtengo la instancia de Sistema
	string titulo, fechaFun;


	
	vector<int> SalasOcupadas;
	bool deseaIngresar = true;

	while (deseaIngresar) {
		
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
		cout << "Cine " + std::to_string(c->getIdCine()) << endl;
		cout << "Direccion :"+c->getDireccion() << endl;
		it->next();
	}
	
	//Selecciona Cine
	int idCine;
	cout << "Ingrese el numero del cine que desee: ";
	cin >> idCine;


	cout << "Ingrese Fecha y hora de la funcion (Ej: 2019/05/18 13:10:00): ";
	cin.ignore();
	getline(cin, fechaFun);

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
		
		//Lista Salas - Mostrar Ocupadas y Disponibles
		//Voy por todas las pelis
		t = sistema->ListarTitulos();
		it = t->getIterator();


		while (it->hasCurrent()) {

			//Voy por todas las funciones de todas las pelis de el cine seleccionado por el user
			ICollection* f = sistema->ListarFunciones(idCine, dynamic_cast<KeyString*>(it->getCurrent())->getValue());
			IIterator* it2 = f->getIterator();

			while (it2->hasCurrent()) {

				DtFuncion* f = dynamic_cast<DtFuncion*>(it2->getCurrent());

				time_t h = f->getHorario();
				//Me fijo si dicha funcion + 3 horas esta en el rango de la hora y fecha que el user puso
				//No me salio ese if xD
				double DiffSeconds = difftime(horario, h);
				if (DiffSeconds < 10800) {
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
			cout << "IdSala " + std::to_string(s->getIdSala()) << endl;
			cout << "cantAsientos :" + std::to_string(s->getCantAsientos()) << endl;
			//Comparamos si esta en la lista de no disponibles para este cine a esa hora
			if (find(SalasOcupadas.begin(), SalasOcupadas.end(), s->getIdSala()) != SalasOcupadas.end()) {
				cout << "Ocupada" << endl;
			}
			else {
				cout << "Disponible" << endl;
			}
			
			it->next();
		}


		//Selecionar Sala
		int idSala;
		bool existeSala = false;
		cout << "Ingrese el numero de sala que desee: ";
		cin >> idSala;


		//Ahora veremos si esta ocupada o no
		
		if (std::find(SalasOcupadas.begin(), SalasOcupadas.end(), idSala) != SalasOcupadas.end()) {
			cout << "Esta seleccionando una sala que esta ocupada" << endl;
		}
		else {
			//Todo bien, hagamos el alta.
			sistema->AltaFuncion(titulo, fechaFun, idCine, idSala);
		}
		

		deseaIngresar = DeseaContinuar("Desea ingresar otra funcion para esta pelicula? (Si/No): ");
	}
}

void OpcionEliminarPelicula()
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

	cout << "Ingrese el titulo de la pelicula a eliminar: ";
	cin.ignore();
	getline(cin, titulo);

	if (!DeseaContinuar("Enserio desea eliminar dicha pelicula? (Si/No): ")) return;

	s->EliminarPelicula(titulo);
	cout << "La pelicula " << titulo << " ha sido eliminada" << endl;
}

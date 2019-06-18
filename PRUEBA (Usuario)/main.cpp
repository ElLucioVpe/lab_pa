#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include "collections/ColReservas.h"
#include "classes/headers/Reserva.h"
//------------PRUEBA USUARIO-----------
#include "collections/ColUsuario.h"
#include "classes/headers/Usuario.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	/*Reserva* example=new Reserva(1,2);
	ColReservas* examp = new ColReservas();
	examp->add(example);
	examp->member(example);*/
	
	Usuario* A = new Usuario("A", "www.imagen.com/profile.jpg", "A123");
	Usuario* B = new Usuario("B", "NO", "B456");
	ColUsuario usuarios;
	usuarios.add(A);
	usuarios.add(B);
	
	if (usuarios.member(A)) {
		cout << "A pertenece a la coleccion" << endl;
	}
	else {
		cout << "A no pertenece a la coleccion" << endl;
	}
    
    //Iterator concreto
    UsuarioIterator it = usuarios.getIterator();
	
	int nro = 1;
    while (it.hasCurrent()) {
    	Usuario* u = it.getCurrent();
        cout << nro << endl;
        cout << "Nickname: " + u->getNickName() << endl;
        cout << "Url Imagen de perfil: " + u->getImgPerfil() << endl;
        cout << "Contrasenia: " + u->getContrasenia() << endl << endl;
        it.next();
        nro ++;
    }
    
    //Ejemplo Iterator generico
	/*IIterator* it = usuarios.getIterator(); // usuarios.getIterator() llamaria al getIterator() de List
	
	int nro = 1;
    while (it->hasCurrent()) {
        Usuario* temp = dynamic_cast<Usuario*>(it->getCurrent());
        cout << nro << endl;
        cout << "Nickname: " + temp->getNickName() << endl;
        cout << "Url Imagen de perfil: " + temp->getImgPerfil() << endl;
        cout << "Contrasenia: " + temp->getContrasenia() << endl << endl;
        it->next();
        nro ++;
    }*/
    
	return 0;
}

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <string>
#include "collections/ColReservas.h"
#include "classes/headers/Reserva.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Reserva* example=new Reserva(1,2);
	ColReservas* examp = new ColReservas();
	examp->add(example);
	examp->member(example);
	return 0;
}

#include "../headers/Usuario.h"

Usuario::Usuario(std::string _nickname, std::string _img, std::string _contra, bool _admin) {
    this->NickName = _nickname;
    this->ImgPerfil = _img;
    this->Contrasenia = _contra;
	this->Admin = _admin;
}

std::string Usuario::getNickName() {
    return this->NickName;
}

std::string Usuario::getImgPerfil() {
    return this->ImgPerfil;
}

std::string Usuario::getContrasenia() {
    return this->Contrasenia;
}

bool Usuario::getAdmin()
{
	return this->Admin;
}

void Usuario::setNickname(std::string _nickname) {
    this->NickName = _nickname;
}

void Usuario::setImgPerfil(std::string _img) {
    this->ImgPerfil = _img;
}

void Usuario::setContrasenia(std::string _contra) {
    this->Contrasenia = _contra;
}

void Usuario::setAdmin(bool _admin)
{
	this->Admin = _admin;
}

bool Usuario::contraCorrecta(std::string c) {
    if (c == this->Contrasenia)
        return true;
    else
        return false;
}

Usuario::~Usuario() {

}

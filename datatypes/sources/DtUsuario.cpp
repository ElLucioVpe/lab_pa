#include "../headers/DtUsuario.h"

DtUsuario::DtUsuario(std::string _nickname, std::string _img, std::string _contra, bool _admin) {
    this->NickName = _nickname;
    this->ImgPerfil = _img;
    this->Contrasenia = _contra;
	this->Admin = _admin;
}

std::string DtUsuario::getNickName() {
    return this->NickName;
}

std::string DtUsuario::getImgPerfil() {
    return this->ImgPerfil;
}

std::string DtUsuario::getContrasenia() {
    return this->Contrasenia;
}

bool DtUsuario::getAdmin()
{
	return this->Admin;
}


bool DtUsuario::contraCorrecta(std::string c) {
    if (c == this->Contrasenia)
        return true;
    else
        return false;
}

DtUsuario::~DtUsuario() {

}
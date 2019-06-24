#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <iostream>
#include <string>

class DtUsuario {
private:
	std::string NickName;
	std::string ImgPerfil;
	std::string Contrasenia;
public:
	DtUsuario(std::string _nickname, std::string _img, std::string _contra);
	std::string getNickName();
	std::string getImgPerfil();
	std::string getContrasenia();

	bool contraCorrecta(std::string c);
	virtual ~DtUsuario();
};

#endif /* DTUSUARIO_H */
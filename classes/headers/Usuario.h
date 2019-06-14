#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include "../../interfaces/ICollectible.h"

class Usuario : public ICollectible {
    private:
        std::string NickName;
        std::string ImgPerfil;
        std::string Contrasenia;
    public:
        Usuario(std::string _nickname, std::string _img, std::string _contra);
        std::string getNickName();
        std::string getImgPerfil();
        std::string getContrasenia();

        void setNickname(std::string _nickname);
        void setImgPerfil(std::string _img);
        void setContrasenia(std::string _contra);

        bool contraCorrecta(std::string c);
        ~Usuario();
}

#endif /* USUARIO_H */
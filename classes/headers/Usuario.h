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
		bool Admin;
    public:
        Usuario(std::string _nickname, std::string _img, std::string _contra, bool _admin);
        std::string getNickName();
        std::string getImgPerfil();
        std::string getContrasenia();
		bool getAdmin();

        void setNickname(std::string _nickname);
        void setImgPerfil(std::string _img);
        void setContrasenia(std::string _contra);
		void setAdmin(bool _admin);

        bool contraCorrecta(std::string c);
		~Usuario();
};

#endif /* USUARIO_H */

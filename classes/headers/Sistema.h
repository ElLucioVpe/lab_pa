#include "../../interfaces/ISistema.h"
#include "../../collections/ColUsuarios.h"
#include "../../collections/ColPeliculas.h"
#include "../../collections/ColCines.h"

class Sistema : public ISistema {
	private:
		static Sistema* instance;
		Sistema();
		
		ColUsuarios* usuarios;
        ColPeliculas* peliculas;
        ColCines* cines;
	public:
    	
		static Sistema* getInstance();
		~Sistema();

		void AltaUsuario(string nick, string img, string contra);
		void AltaPelicula(string titulo, string poster, string sinopsis);
		void AltaCine(int id, string dir);
        bool iniciarSesion(string user, string pass);
        void CrearReserva(int cantAsientos, float costo, int IdFuncion, Usuario u);
		ICollection* ListarTitulos();
        DtPelicula SeleccionarPelicula(string titulo);
        void EliminarPelicula(string titulo);
        void VerInfoPelicula(string titulo);
		ICollection* ListarCines();
        ICollection* ListarCinesPorTitulo(string tituloPelicula);
		ICollection* ListarFunciones(int idCine, string tituloPelicula);
};

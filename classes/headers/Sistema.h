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

		void AltaUsuario(string nick, string img, string contra, bool admin);
		void AltaPelicula(string titulo, string poster, string sinopsis);
		void AltaCine(string dir);
		void AltaSala(int idCine, int cantAsientos);
		void AltaFuncion(string titulo, string horario, int idCine, int idSala);
		void AltaComentario(string texto, string pelicula, string autor);
        DtUsuario* iniciarSesion(string user, string pass);
        void CrearReserva(int cantAsientos, float costo, string titulo, int IdFuncion, string u, string banco, string financiera);
		ICollection* ListarTitulos();
        DtPelicula* SeleccionarPelicula(string titulo);
        void EliminarPelicula(string titulo);
        void VerInfoPelicula(string titulo);
		ICollection* ListarCines();
        ICollection* ListarCinesPorTitulo(string tituloPelicula);
		ICollection* ListarFunciones(int idCine, string tituloPelicula);
		ICollection* ListarSalas(int idCine);
		int DarUltimoCine();
        Usuario * ListarUsuario(DtUsuario * user);
};

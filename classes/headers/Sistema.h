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

		//-----
        bool iniciarSesion(string user, string pass);
        void CrearReserva(int cantAsientos, float costo, int IdFuncion, Usuario u);
		set<string> ListarTitulos();
        DtPelicula SeleccionarPelicula(string titulo);
        void EliminarPelicula(string titulo);
        void VerInfoPelicula(string titulo);
		set<int> ListarCines();
        ICollection* ListarCinesPorTitulo(string tituloPelicula);
		ICollection* ListarFunciones(int idCine, string tituloPelicula);
};

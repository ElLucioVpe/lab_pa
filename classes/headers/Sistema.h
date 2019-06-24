#include "../../interfaces/ISistema.h"
#include "../../collections/ColUsuarios.h"
#include "../../collections/ColPeliculas.h"
#include "../../collections/ColCines.h"

class Sistema : public ISistema {
    public:
        Sistema();
        ~Sistema();
        bool iniciarSesion(string user, string pass);
        void CrearReserva(int cantAsientos, float costo, int IdFuncion, Usuario u);
        set<string> ListarTitulos();
        DtPelicula SeleccionarPelicula(string titulo);
        void EliminarPelicula(string titulo);
        void VerInfoPelicula(string titulo);
        set<int> ListarCines();
        set<DtCine> ListarCinesPorTitulo(string tituloPelicula);
        set<DtFuncion> ListarFunciones(int idCine, string tituloPelicula);

    private:
        ColUsuarios usuarios;
        ColPeliculas peliculas;
        ColCines cines;
};
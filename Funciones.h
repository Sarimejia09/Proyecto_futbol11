#ifndef Funciones_h
#define Funciones_h

#include <string>

//crear el struct
struct Jugador {
    std::string nombreCompleto;
    std::string nombre;
    std::string apellido;
    std::string nacionalidad;
    std::string posicion;
    std::string club;
};

struct jugador {
    std::string NombreCompleto;
    std::string Nombre;
    std::string Club;
    std::string Apellido;
    std::string Nacionalidad;
};


void ObtenerDatos(Jugador jugadores[]);
void ImprimirTabla(std::string tabla[12][16]);
void ComprobarPalabra(std::string intento, int ni, std::string jugador, std::string tabla[12][16]);
int main();
void ImprimirGrid(std::string Grid[4][4]);
int IdJugador(std::string ju, jugador jGrid[1000], std::string Grid[4][4]);
int ClubesPaises(jugador jGrid[1000], std::string clubes[3], std::string paises[3], std::string Grid[4][4], std::string ju, int id); 
void ObtenerDatosGrid(jugador jGrid[1000]);
bool Ganar(std::string Grid[4][4]);
void GuardarVictoria(std::string juego);
void MostrarVictorias();

//printables
void LineaHorizontal();
void Centrar(int x);
void NuevaPantalla();
void PantallaGanar();
void PantallaPerder();

#endif
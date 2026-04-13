#include <iostream>
#include <cstdlib> 
#include "Juegos.h"
#include "Funciones.h"

int correcto=0;

int main () {

    LineaHorizontal();
    Centrar(10);
    std::cout<<"Bienvenidx \n";
    LineaHorizontal();
    std::cout<<"Que deseas jugar? \n"<<
    "1. Adivina el jugador con 3 pistas \n"<<
    "2. Worldle\n"<<
    "3. Grid\n";
    std::string respuesta;
    std::cin>>respuesta;
    NuevaPantalla();
    std::string juego;
    if (respuesta=="1") {
        AdivinaElJugador();
    } else if(respuesta=="2") {
        Worldle();
    } else if(respuesta=="3") {
        JuegoGrid();
    } else {
        PantallaPerder();
    }
}


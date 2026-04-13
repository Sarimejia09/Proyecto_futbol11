#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Funciones.h"

void ImprimirTabla(std::string tabla[12][16]) {
    
    for (int i=0; i < 12; i++) {
        for (int j=0; j < 16; j++) {
            if (tabla[i][j] == "LC") {
                    std::cout << "\033[32m" << tabla[i][j] << "\033[0m\t"; // verde
                } else if (tabla[i][j] == "LI") {
                    std::cout << "\033[33m" << tabla[i][j] << "\033[0m\t"; // amarillo
                } else if (tabla[i][j] == "X") {
                    std::cout << "\033[31m" << tabla[i][j] << "\033[0m\t"; // rojo
                } else {
                    std::cout << tabla[i][j] << "\t";
                }
            }
            std::cout << "\n";
    }
}


void ObtenerDatos(Jugador jugadores[]) {

    //importar la base de datos :)
    std::ifstream archivo("jugadores.csv");
    std::string linea;

    //guardar los datos :p
    int i = 0;

    std::getline(archivo, linea);

    while (getline(archivo, linea) && i < 50) {
        std::stringstream ss(linea);
        std::string dato;

        getline(ss, jugadores[i].nombreCompleto, ',');
        getline(ss, jugadores[i].nacionalidad, ',');
        getline(ss, jugadores[i].posicion, ',');
        getline(ss, jugadores[i].club, ',');

        //Separar en nombre y apellido
        std::stringstream st(jugadores[i].nombreCompleto);
        st>>jugadores[i].nombre;
        st>>jugadores[i].apellido;

        i++;
    }
    archivo.close();

}

void ComprobarPalabra(std::string intento, int ni, std::string jugador, std::string tabla[12][16]) {

    for (int i = 0; i < intento.size(); i++) {

        if (intento[i] == jugador[i]) {
            tabla[(ni*2)-1][i] = "LC";  // correcta posición
        } else {
            bool existe = false;

            for (char ch : jugador) {
                if (intento[i] == ch) {
                    existe = true;
                    break;
                }
            }

            if (existe) {
                tabla[(ni*2)-1][i] = "LI"; // letra existe
            } else {
                tabla[(ni*2)-1][i] = "X"; // no existe
            }
        }
    }
}

//===================================Funciones para Grid=============================================

void ObtenerDatosGrid(jugador jGrid[1000]) {

    //importar la base de datos :)
    std::ifstream archivo("Jugadores_Grid.csv");
    std::string linea;

    //guardar los datos :p
    std::getline(archivo, linea);

    int i = 0;

    while (getline(archivo, linea) && i < 643) {
        std::stringstream ss(linea);
        std::string dato;

        getline(ss, jGrid[i].NombreCompleto, ',');
        getline(ss, jGrid[i].Nacionalidad, ',');
        getline(ss, jGrid[i].Club, ',');


        //Separar en nombre y apellido
        std::stringstream st(jGrid[i].NombreCompleto);
        st>>jGrid[i].Nombre;
        st>>jGrid[i].Apellido;

        i++;
    }
    archivo.close();

}

std::string CentrarTexto(std::string texto, int ancho) {
    int espacios = ancho - texto.length();
    int izquierda = espacios / 2;
    int derecha = espacios - izquierda;

    return std::string(izquierda, ' ') + texto + std::string(derecha, ' ');
}

void ImprimirGrid(std::string Grid[4][4]) {
        int ancho = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (Grid[i][j].length() > ancho) {
                ancho = Grid[i][j].length();
            }
        }
    }

    ancho += 2; 

    for (int i = 0; i < 4; i++) {
        std::cout<<"|";
        for (int j = 0; j < 4; j++) {
            std::cout << CentrarTexto (Grid[i][j], ancho) <<"|";
        }
        std::cout << "\n";
    }
}

int IdJugador(std::string ju, jugador jGrid[1000], std::string Grid[4][4]) {
    for (int i=1; i<642; i++) {
        if (jGrid[i].Nombre==ju || jGrid[i].Apellido==ju || jGrid[i].NombreCompleto==ju) {
            return i;
        } 
    }
    NuevaPantalla();
    std::cout<<"El jugador " <<ju<<" no esta en el sistema, intentalo de nuevo \n\n";
    ImprimirGrid(Grid);
    return 0;
}

int ClubesPaises(jugador jGrid[1000], std::string clubes[3], std::string paises[3], std::string Grid[4][4], std::string ju, int id) {
    if (id!=0) {
        for (int i=0; i<7; i++) {
            for (int j=0; j<3; j++) {
                for (int k=0; k<3; k++) {
                    if (jGrid[id+i].Nacionalidad == paises[j] && jGrid[id+i].Club == clubes[k]) {
                        if (jGrid[id+i].NombreCompleto==ju || jGrid[id+i].Nombre==ju || jGrid[id+i].Apellido==ju) {
                            if (Grid[j+1][k+1]=="?") {
                                NuevaPantalla();
                                Grid[j+1][k+1]=jGrid[id+i].NombreCompleto;
                                std::cout<<"El jugador "<<jGrid[id+i].NombreCompleto<<" sirve :) \n\n";
                                ImprimirGrid(Grid);
                            } 
                        }     
                    }
                }   
            } 
        }   
        NuevaPantalla();
        std::cout<<"El jugador " <<ju <<" no sirve para ninguna casilla intentalo de nuevo: \n\n";
        ImprimirGrid(Grid);
    } 
}

bool Ganar(std::string Grid[4][4]) {
    int ganar=0;
    for (int i=1; i<4; i++) {
        for (int j=1; j<4; j++) {
            if (Grid[i][j]!="?") {
                ganar++;
            }
            if (ganar==9) {
                return true;
            }
        }
    }
}

//=========================================Printables==============================================

void LineaHorizontal() {

    for(int i = 0; i < 140; i++)
        std::cout << "=";
    std::cout << "\n";
    
}

void Centrar(int x) {
    for(int i = 0; i < 70-x; i++) {
        std::cout << " ";
    }
}

void NuevaPantalla() {
    system("cls");
}

void PantallaGanar() {

    NuevaPantalla();
    LineaHorizontal();

    Centrar(40);
    std::cout<<" _____    _____           __    _     _____   _   _   _____     ___    ____     ___ \n";
    Centrar(40);
    std::cout<<"|  _  \\  |__ __|  _____  |  \\  | |   |____ | | | | | /  _  \\   /   \\  |  _ \\   / _ \\  \n";
    Centrar(40);
    std::cout<<"| |_)  |   | |   |  ___| |   \\ | |       | | | | | | | / \\_|  |  _  | | | | | | / \\ | \n";
    Centrar(40);
    std::cout<<"|   __/    | |   | |___  | |\\ \\| |       | | | | | | | |___   | |_| | | | | | | | | | \n";
    Centrar(40);
    std::cout<<"|  _  \\    | |   |  ___| | | \\   |       | | | | | | |  _  \\  |  _  | | | | | | | | | \n";
    Centrar(40);
    std::cout<<"| |_)  |  _| |_  | |___  | |  \\  |    ___/ / | \\_/ | | |_) |  | | | | | |_| | | \\_/ | \n";
    Centrar(40);
    std::cout<<"|_____/  |_____| |_____| |_|   \\_|   |____/  \\_____/  \\____/  |_| |_| |____/   \\___/ \n";

}

void PantallaPerder() {

    NuevaPantalla();
    LineaHorizontal();

    Centrar(35);
    std::cout<<" ____            ____    ____    _____    ____   _____ \n";
    Centrar(35);
    std::cout<<"|  _ \\   _____  |  _ \\  |  _ \\  |__ __|  / _  \\ |__ __|  _____  \n";
    Centrar(35);
    std::cout<<"| |_) | |  ___| | |_) | | | | |   | |   | | |_|   | |   |  ___| \n";
    Centrar(35);
    std::cout<<"|  __/  | |___  |   _/  | | | |   | |    \\ \\      | |   | |___ \n";
    Centrar(35);
    std::cout<<"| |     |  ___| |   \\   | | | |   | |    _ \\ \\    | |   |  ___| \n";
    Centrar(35);
    std::cout<<"| |     | |___  | |\\ \\  | |_| |  _| |_  | |_| |   | |   | |___ \n";
    Centrar(35);
    std::cout<<"|_|     |_____| |_| \\_\\ |____/  |_____| \\____/    |_|   |_____| \n";
 
}


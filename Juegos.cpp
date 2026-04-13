#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <algorithm> //Minusculas

#include "Juegos.h"
#include "Funciones.h"

void ObtenerDatos(Jugador jugadores[]);
void LineaHorizontal();
void ImprimirTabla(std::string tabla[12][16]);
void ComprobarPalabra(std::string intento, int ni, std::string jugador, std::string tabla[12][16]);
void PantallaGanar();
void PantallaPerder();

Jugador jugadores[50];
std::string tabla[12][16];
jugador jGrid[1000];

void AdivinaElJugador() {

    LineaHorizontal();
    Centrar(18);
    std::cout<<"Adivina el Jugador \n";
    LineaHorizontal();

    ObtenerDatos(jugadores);
    
    std::string intentos="si";
    int puntaje=0;
    int nintento=0;

    while (intentos=="si") {

        Centrar(25);
        std::cout<<"Puntaje: "<<puntaje<<"\t Numero de intento: "<<nintento<<"\n";
        LineaHorizontal();
        std::cout<<"Nacionalidad \t posicion \t club \n";

        //escoger jugador aleatorio
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int n = (std::rand() % (1 - 50 + 1) + 1 );
        std::cout<<jugadores[n].nacionalidad<<"\t";
        std::cout<<jugadores[n].posicion<<"\t";
        std::cout<<jugadores[n].club<<"\n \n";

        std::cout<<"Ingresa el jugador: ";
        std::string intento;
        std::cin>>intento;
        transform(intento.begin(), intento.end(), intento.begin(), ::tolower);

        if (intento==jugadores[n].nombreCompleto || intento==jugadores[n].nombre || intento==jugadores[n].apellido) {
            PantallaGanar();
            std::cout<<"\n";
            Centrar(6);
            std::cout<<"+10pts \n";
            LineaHorizontal();
            puntaje+=10;
        } else {
            PantallaPerder();
            std::cout<<"\n";
            Centrar(11+jugadores[n].nombreCompleto.size());
            std::cout<<"El jugador es: "<<jugadores[n].nombreCompleto<<"\t -5pts \n \n";
            LineaHorizontal();
            puntaje-=5;
        }

        nintento++;
        std::cout<<"Quieres jugar de nuevo? si o no ";
        std::cin>>intentos;
        NuevaPantalla();

    }

    if (intentos=="no") {
        std::cout<<"Quieres volver al menu principal? si o no ";
        std::string respusta;
        std::cin>>respusta;
        if (respusta=="si") {
            NuevaPantalla();
            main();
        }
    }

}

void Worldle () {

    ObtenerDatos(jugadores);

    std::string respuesta="si";

    while (respuesta=="si") {  

        NuevaPantalla();

        //Escoger jugador aleatorio
        std::string jugador;
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int n = (std::rand() % (1 - 50 + 1) + 1 );
        jugador=jugadores[n].apellido;
        int c = jugador.size();

        std::cout<<"Nombre de jugador de "<<c<<" letas \n";
        LineaHorizontal();

        for (int i=0; i<12; i++) { 
            for(int j=0; j<c; j++) {
                if (i % 2 == 0){
                    tabla[i][j]="| |";
                } else {
                    tabla[i][j]=" ";
                }
            }    
        }
        ImprimirTabla(tabla);
        
        int correcto=0;
        int ni=1;
        while (ni<7 && correcto!=c) {

            std::string intento;
            std::cout<<"Ingresa el nombre: ";
            std::cin>>intento;
            transform(intento.begin(), intento.end(), intento.begin(), ::tolower);

            NuevaPantalla();

            if (intento.size()==c) {

                for (int j=0; j<c; j++){
                    tabla [(ni*2)-2][j]=intento[j];
                }
                
                ComprobarPalabra(intento, ni, jugador, tabla);
                ImprimirTabla(tabla);

                correcto=0;
                for (int i=0; i<c; i++){
                    if (tabla[(ni*2)-1][i] == "LC") {
                        correcto++;
                    }
                }

                ni++;

            } else if (intento.size()<c) { 
                std::cout<<"Nombre muy corto, intentalo de nuevo \n"; 

            } else {
                std::cout<<"Nombre muy largo, intentalo de nuevo \n";
            } 
        }   
        if (correcto==c) {
            PantallaGanar();

            std::cout<<"\n";
            Centrar(26);
            std::cout<<"Lo lograste en: "<<ni-1<<" intentos \n";
            LineaHorizontal();
            std::cout<<"\n"<<"Quieres jugar de nuevo? si o no ";
            std::cin>>respuesta;
        } else if (correcto != c) {
            PantallaPerder();
            std::cout<<"\n";
            Centrar(24+jugadores[n].apellido.size());
            std::cout<<"El jugador correcto es: "<<jugadores[n].apellido<<"\n";
            LineaHorizontal();
            std::cout<<"\n \nQuieres jugar de nuevo? si o no ";
            std::cin>>respuesta; 
        }
    } 

    if (respuesta=="no") {
        std::cout<<"Quieres volver al menu principal? si o no ";
        std::string respusta;
        std::cin>>respusta;
        if (respusta=="si") {
            NuevaPantalla();
            main();
        }
    }

}

void JuegoGrid () {

    LineaHorizontal();
    Centrar(4);
    std::cout<<"Grid \n";
    LineaHorizontal();
    std::cout<<"La tabla puede tardar un poco en cargar, ten paciencia...";

    std::string clubes[3];
    std::string paises[3];
    std::string Grid[4][4];

    ObtenerDatosGrid(jGrid);
    
    bool correcto=false;

    while(correcto==false) {

        bool dif=false;

        while (dif==false) {
        
            std::srand(std::time(NULL));
            int n = (std::rand() % 643) + 1;
            clubes[0]= jGrid[n].Club;
            Grid[0][1] = clubes[0];
            paises[0]= jGrid[n].Nacionalidad;
            Grid[1][0] = paises[0];

            std::srand(std::time(NULL)*2);
            int n1 = (std::rand() % 643) + 1;
            clubes[1]= jGrid[n1].Club;
            Grid[0][2] = clubes[1];
            paises[1]= jGrid[n1].Nacionalidad;
            Grid[2][0] = paises[1];
            
            std::srand(std::time(NULL)*3);
            int n2 = (std::rand() % 643) + 1;
            clubes[2]= jGrid[n2].Club;
            Grid[0][3] = clubes[2];
            paises[2]= jGrid[n2].Nacionalidad;
            Grid[3][0] = paises[2];

            dif = clubes[0]!=clubes[1] && clubes[1]!=clubes[2] && clubes[0]!=clubes[2] && paises[0]!=paises[1] && paises[1]!=paises[2] && paises[0]!=paises[2];

        }  
        
        Grid[1][1]="?";
        Grid[1][2]="";
        Grid[1][3]="";
        Grid[2][1]="";
        Grid[2][2]="?";
        Grid[2][3]="";
        Grid[3][1]="";
        Grid[3][2]="";
        Grid[3][3]="?";

        int contador=3;

        for (int i=0; i<3; i++) { //filas
            for (int j=0; j<3; j++) { //columnas
                for (int k=1; k<642; k++) {
                    if (Grid[i+1][j+1]=="") {
                        if (jGrid[k].Club==clubes[j] && jGrid[k].Nacionalidad==paises[i]) {
                            contador++;
                            Grid[i+1][j+1]="?";
                        }
                    }
                }
            }
        }

        
        if (contador==9) {
            correcto=true;
        } else {
            correcto=false;
        }

    }

    ImprimirGrid(Grid);

    while(true) {

        std::string respuesta;

        std::string ju;
        std::cout<<"Ingresa el jugador: ";
        std::getline(std::cin, ju);

        IdJugador(ju, jGrid, Grid);

        int id=IdJugador(ju, jGrid, Grid);

        ClubesPaises(jGrid, clubes, paises, Grid, ju, id);
        Ganar(Grid);
        
        if (Ganar(Grid)==true) {
            PantallaGanar();
            std::cout<<"\n";
            LineaHorizontal();
            std::cout<<"\n"<<"Quieres jugar de nuevo? si o no ";
            std::cin>>respuesta;
        } 
        if (respuesta=="si") {
            NuevaPantalla();
            JuegoGrid();
        }else if (respuesta=="no") {
            std::cout<<"Quieres volver al menu principal? si o no ";
            std::string respusta;
            std::cin>>respusta;
            if (respusta=="si") {
                NuevaPantalla();
                main();
            }
        }
    }
}       

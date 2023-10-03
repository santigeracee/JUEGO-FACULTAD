#ifndef TODO_H_INCLUDED
#define TODO_H_INCLUDED
#include "Funciones.h"
using namespace std;
int todo(){

    srand(time(0));

    int numJugadores;
    string nombreJugador1, nombreJugador2;
    int puntajeJugador1 = 0, puntajeJugador2 = 0;
    int seguirjuego=1;
    int ronda = 1;
    int maxPuntaje = 0;
    string ganador;


    while (seguirjuego==1){
        int puntajeJugador1 = 0, puntajeJugador2 = 0;
        int ronda = 1;

    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::BLACK);

    rlutil::cls();

    rlutil::locate (42,12);
    cout<< "BIENVENIDOS A QUINIENTOS O ESCALERA"<<endl;
    rlutil::locate (44,13);
    cout<< "||------ MENU PRINCIPAL ------||"<<endl;
    rlutil::locate (42,15);
    cout<< "1. JUEGO NUEVO PARA UN JUGADOR"<<endl;
    rlutil::locate (42,16);
    cout<< "2. JUEGO NUEVO PARA DOS JUGADORES"<<endl;
    rlutil::locate (42,17);
    cout<< "0. FIN DEL PROGRAMA" <<endl;
    rlutil::locate (42,18);
    cout<< "LA PUNTUACION MAXIMA FUE " << maxPuntaje <<endl;
    rlutil::locate (42,19);
    cout<< "-----------------------------------"<<endl;
    cout<< endl;
    rlutil::locate (44,20);
    cout<< "SELECCIONE UNA DE LAS OPCIONES "<<endl;
    rlutil::locate (58,21);
    cin >> numJugadores;

    system("cls");


    switch (numJugadores) {
        case 1:
        rlutil::locate (44,13);
        cout<< "----MODO DE UN JUGADOR----"<<endl;
        cout<< endl;
        rlutil::locate (44,14);
        cout<< "INGRESE NOMBRE DEL JUGADOR: "<<endl;
        rlutil::locate (52,15);
        cin >> nombreJugador1;

        break;


        case 2:
        rlutil::locate (44,13);
        cout<< "----MODO DOS JUGADORES----" <<endl;
        cout<< endl;
        rlutil::locate (42,15);
        cout<< "INGRESE NOMBRE DEL PRIMER JUGADOR: "<<endl;
        rlutil::locate (53,16);
        cin >> nombreJugador1;
        rlutil::locate (42,17);
        cout<< "INGRESE NOMBRE DEL SEGUNDO JUGADOR: "<<endl;
        rlutil::locate (53,18);
        cin >> nombreJugador2;
        break;

        case 0:

            return 0;

        break;

    }

    int numRondas;
    rlutil::locate (39,20);
    cout << "INGRESE EL NUMERO DE RONDAS A JUGAR: ";

    rlutil::locate (56,21);
    cin >> numRondas;

    system("cls");

    while (ronda <= numRondas) {


        if (numJugadores == 1){

            int puntajeronda = 0;

        for(int i=0;i<3;i++){

            rlutil::locate (50,3);
            cout << "TURNO DE " << nombreJugador1 << endl;
            rlutil::locate (53,5);
            cout << "RONDA " << ronda << " DE " << numRondas << endl;
            rlutil::locate (51,7);
            cout<< "PUNTAJE TOTAL " <<puntajeJugador1 <<endl;
            rlutil::locate (51,9);
            cout << "TIRADA NUMERO " << i+1 << endl;
            rlutil::locate (1,28);
            cout << "ENTER PARA LANZAR LOS DADOS...";
            rlutil::anykey ();


            int dados[6];
            lanzarDados(dados, 6);


            int puntaje = calcularPuntaje(dados, 6);
            rlutil::locate (51,19);
            cout << "PUNTAJE OBTENIDO: " << puntaje << endl;
            if (puntaje ==0){
                puntajeronda=0;
                i+=3;
            }

             if (puntaje==500){
            i+=3;
            ronda+=numRondas;
             }

            if (puntaje>puntajeronda){
                puntajeronda=puntaje;
            }


            rlutil::anykey ();
            system("cls");

        }

            puntajeJugador1 += puntajeronda;
            if (puntajeJugador1>=500){
                ronda+=numRondas;
            }


            system("cls");

            rlutil::locate (47,15);
            cout<<"FIN DE LA RONDA NUMERO " << ronda <<endl;
            rlutil::locate (47,16);
            cout<<"PUNTAJE DE LA RONDA: "<<puntajeronda<<endl;

            rlutil::anykey ();
            system("cls");

            ganador = nombreJugador1;
            maxPuntaje = max(maxPuntaje, puntajeJugador1);

        } else if (numJugadores == 2) {

            int puntajeronda1=0;
            for(int i=0;i<3;i++){

            rlutil::locate (50,3);
            cout << "TURNO DE " << nombreJugador1 << endl;
            rlutil::locate (53,5);
            cout << "RONDA " << ronda << " DE " << numRondas << endl;
            rlutil::locate (51,7);
            cout<< "PUNTAJE TOTAL " <<puntajeJugador1 <<endl;
            rlutil::locate (51,9);
            cout << "TIRADA NUMERO " << i+1 << endl;
            rlutil::locate (1,28);
            cout << "ENTER PARA LANZAR LOS DADOS...";
            rlutil::anykey ();

            int dadosJugador1[6];
            lanzarDados(dadosJugador1, 6);


            int puntajetiro1 = calcularPuntaje(dadosJugador1, 6);
            rlutil::locate (46,19);
            cout << "PUNTAJE OBTENIDO POR " << nombreJugador1 << ": " << puntajetiro1 << endl;
            if (puntajetiro1 ==0){
                puntajeronda1=0;
                i+=3;
            }
            if (puntajetiro1==500){
                i+=3;
                ronda+=numRondas;
            }
            if (puntajetiro1>puntajeronda1){
                puntajeronda1=puntajetiro1;
            }

            rlutil::anykey ();
            system("cls");

            }

            int puntajeronda2=0;
            for(int i=0;i<3;i++){
            rlutil::locate (50,3);
            cout << "TURNO DE " << nombreJugador2 << endl;
            rlutil::locate (53,5);
            cout << "RONDA " << ronda << " DE " << numRondas << endl;
            rlutil::locate (51,7);
            cout<< "PUNTAJE TOTAL " <<puntajeJugador2 <<endl;
            rlutil::locate (51,9);
            cout << "TIRADA NUMERO " << i+1 << endl;
            rlutil::locate (1,28);
            cout << "ENTER PARA LANZAR LOS DADOS...";
            rlutil::anykey ();



            int dadosJugador2[6];
            lanzarDados(dadosJugador2, 6);


            int puntajetiro2 = calcularPuntaje(dadosJugador2, 6);

            rlutil::locate (46,19);
            cout << "PUNTAJE OBTENIDO POR " << nombreJugador2 << ": " << puntajetiro2 << endl;

            if (puntajetiro2 ==0){
                puntajeronda2=0;
                i+=3;
            }

            if (puntajetiro2==500){
            i+=3;
            ronda+=numRondas;
            }


            if (puntajetiro2>puntajeronda2){
                puntajeronda2=puntajetiro2;

            }

            rlutil::anykey ();
            system("cls");

            }


            puntajeJugador1 += puntajeronda1;
            puntajeJugador2 += puntajeronda2;



            rlutil::locate (44,13);
            cout<< "FIN DE LA RONDA " <<ronda << endl;
            rlutil::locate (44,14);
            cout<< "PUNTAJE DE "<< nombreJugador1 << " " <<puntajeJugador1<<endl;
            rlutil::locate (44,15);
            cout<<"PUNTAJE DE "<< nombreJugador2 << " " <<puntajeJugador2<<endl;

            rlutil::anykey ();
            system("cls");

            if (puntajeJugador1 >= 500 && puntajeJugador1 > puntajeJugador2) {
                ganador = nombreJugador1;
                maxPuntaje = max(maxPuntaje, puntajeJugador1);
                break;

            } else if (puntajeJugador2 >= 500 && puntajeJugador2 > puntajeJugador1) {
                ganador = nombreJugador2;
                maxPuntaje = max(maxPuntaje, puntajeJugador2);
                break;
            }
        }


        ronda++;
    }

    rlutil::locate (48,6);
    cout << "*** FIN DEL JUEGO ***" << endl;
    if (numJugadores == 1) {
    rlutil::locate (48,13);
    cout << "JUGADOR: " << nombreJugador1 << endl;
    rlutil::locate (40,14);
    cout << "PUNTAJE OBTENIDO EN LA PARTIDA: " << puntajeJugador1 << endl;
    rlutil::locate (43,15);
    cout << "PUNTAJE MAXIMO: " << maxPuntaje << " PUNTOS" << endl;

    } else if (numJugadores == 2) {
        rlutil::locate (48,13);
        cout << "JUGADOR 1 (" << nombreJugador1 << "): " << puntajeJugador1 << " PUNTOS" << endl;
        rlutil::locate (48,14);
        cout << "JUGADOR 2 (" << nombreJugador2 << "): " << puntajeJugador2 << " PUNTOS" << endl;
        if(puntajeJugador1>maxPuntaje){
            maxPuntaje=puntajeJugador1;
        }
        if(puntajeJugador2>maxPuntaje){
            maxPuntaje=puntajeJugador2;
        }
        if(puntajeJugador1>puntajeJugador2){
            ganador=nombreJugador1;
        }
        if(puntajeJugador2>puntajeJugador1){
            ganador=nombreJugador2;
        }

        rlutil::locate (48,15);
        cout << "PUNTAJE MAXIMO: " << maxPuntaje << " PUNTOS" << endl;
        rlutil::locate (48,16);
        cout << "GANADOR: " << ganador << endl;
    }
    rlutil::locate (35,22);
    cout<< "QUERES SEGUIR JUGANDO, INGRESA 1, SINO PRESIONA 2"<<endl;\
    rlutil::locate (43,23);
    cin>> seguirjuego;
    }
}



#endif // TODO_H_INCLUDED

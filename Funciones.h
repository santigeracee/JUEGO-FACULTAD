#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include <iostream>


// Función para lanzar los dados y obtener los valores
void lanzarDados(int dados[], int numDados) {
    for (int i = 0; i < numDados; i++) {
        dados[i] = rand() % 6 + 1;


dibujarDados(dados[0], 32, 12);

dibujarDados(dados[1], 42, 12);

dibujarDados(dados[2], 52, 12);

dibujarDados(dados[3], 62, 12);

dibujarDados(dados[4], 72, 12);

dibujarDados(dados[5], 82, 12);;

    }
}



// Función para calcular el puntaje de un lanzamiento
int calcularPuntaje(int dados[], int numDados) {
    int puntaje = 0;
    int contador[7] = {0}; // Contador de cada valor

    for (int i = 0; i < numDados; i++) {
        contador[dados[i]]++;
    }

    // Verificar si hay escalera
    bool escalera = true;
    for (int i = 1; i <= 6; i++) {
        if (contador[i] != 1) {
            escalera = false;
            break;
        }
    }
    if (escalera) {
        rlutil::locate (51,25);
        cout << "ESCALERA HAS GANADO " << endl;
        puntaje = 500;
        return puntaje;
    }

    // Verificar si hay sexteto de 6
    if (contador[6] == 6) {
        rlutil::locate (51,18);
        cout << "SEXTETO DE 6 " << endl;
        puntaje = 0;
        return puntaje;
    }

    // Verificar si hay sexteto
    for (int i = 1; i <= 5; i++) {
        if (contador[i] == 6) {

            rlutil::locate (51,18);
            cout << "SEXTETO DE " << i << endl;
            puntaje += i * 50;
            return puntaje;
        }
    }

    // Verificar si hay trío
    for (int i = 1; i <= 6; i++) {
        if (contador[i] >= 3) {

            rlutil::locate (56,18);
            cout << "TRIO DE " << i << endl;
            puntaje = i * 10;

        }
        if (i==6 && puntaje!=0){
            return puntaje;
        }

    }

    // Calcular suma de dados
    for (int i = 1; i <= 6; i++) {
        puntaje += i * contador[i];
    }

    return puntaje;
}

#endif // FUNCIONES_H_INCLUDED

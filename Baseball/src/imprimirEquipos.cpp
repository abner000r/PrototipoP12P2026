#include "../include/imprimirEquipos.h"
#include "../include/Estadisticas.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

void imprimirEquipos::llamaCiclo()
{
    float matriz_equipo_1[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1];
    float matriz_equipo_2[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1];
    float matriz_equipo_3[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1];

    char jugadores[NUMERO_JUGADORES][MAXIMA_LONGITUD_CADENA] = {"Aaron", "Betts", "Judge", "Ohtani", "Soto"};
    char opcion;
    bool repetir = true;

    Estadisticas stats;  // Crear objeto de la clase

    do {
        system("cls");
        cout << "=== COMPARATIVO DE EQUIPOS DE BEISBOL ===\n";

        stats.llenarMatriz(matriz_equipo_1);
        float prom1 = stats.imprimirMatriz(matriz_equipo_1, jugadores, "LOS YANKEES");

        stats.llenarMatriz(matriz_equipo_2);
        float prom2 = stats.imprimirMatriz(matriz_equipo_2, jugadores, "LOS DODGERS");

        stats.llenarMatriz(matriz_equipo_3);
        float prom3 = stats.imprimirMatriz(matriz_equipo_3, jugadores, "LOS ROJOS");

        cout << "\n=== RESULTADOS ===\n";
        if (prom1 > prom2 && prom1 > prom3)
            cout << "CAMPEON: LOS YANKEES (Promedio: " << prom1 << ")\n";
        else if (prom2 > prom1 && prom2 > prom3)
            cout << "CAMPEON: LOS DODGERS (Promedio: " << prom2 << ")\n";
        else if (prom3 > prom1 && prom3 > prom2)
            cout << "CAMPEON: LOS ROJOS (Promedio: " << prom3 << ")\n";
        else
            cout << "EMPATE entre equipos\n";

        cout << "\n¿Otro cálculo? (s/n): ";
        cin >> opcion;
        if (opcion == 'n' || opcion == 'N')
            repetir = false;

    } while (repetir);
}

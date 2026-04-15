#include "../include/Estadisticas.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

Estadisticas::Estadisticas()
{
    // Constructor - inicialización
}

Estadisticas::~Estadisticas()
{
    // Destructor - limpieza
}

int Estadisticas::busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void Estadisticas::llenarMatriz(float matriz[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_JUGADORES; y++)
    {
        float suma = 0;
        int estadistica = 0;
        for (x = 0; x < NUMERO_ESTADISTICAS; x++)
        {
            if (x == 0)  // Hits
                estadistica = busquedaAleatorios(MIN_HITS, MAX_HITS);
            else if (x == 1)  // Carreras
                estadistica = busquedaAleatorios(MIN_CARRERAS, MAX_CARRERAS);
            else if (x == 2)  // Home Runs
                estadistica = busquedaAleatorios(MIN_HR, MAX_HR);
            else if (x == 3)  // RBIs
                estadistica = busquedaAleatorios(MIN_RBI, MAX_RBI);

            suma += (float)estadistica;
            matriz[y][x] = estadistica;
        }
        matriz[y][NUMERO_ESTADISTICAS] = suma;
    }
}

void Estadisticas::imprimirMatrizLinea()
{
    cout << "+-------";
    for (int x = 0; x < NUMERO_ESTADISTICAS + 1; x++)
        cout << "+--------";
    cout << "+\n";
}

float Estadisticas::imprimirMatriz(float matriz[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1],char jugadores[NUMERO_JUGADORES][MAXIMA_LONGITUD_CADENA],const char* nombreEquipo)
{
    cout << "\n" << nombreEquipo << endl;
    cout << "(Hits) Hits  (Car) Carreras  (HR) Home Runs  (RBI) RBIs" << endl;
    imprimirMatrizLinea();
    cout << " Jugador | Hits | Carreras | HR | RBI | Total\n";
    imprimirMatrizLinea();

    float totalGeneral = 0;
    float maxTotal = matriz[0][NUMERO_ESTADISTICAS];// Calcula el numero mayor de las estadisticas
    float minTotal = matriz[0][NUMERO_ESTADISTICAS]; // alcula el numero menor de las estadisticas
    char mejorJugador[MAXIMA_LONGITUD_CADENA];
    char peorJugador[MAXIMA_LONGITUD_CADENA];

    strcpy(mejorJugador, jugadores[0]);
    strcpy(peorJugador, jugadores[0]);

    for (int y = 0; y < NUMERO_JUGADORES; y++)
    {
        cout << " " << jugadores[y];
        for (int x = 0; x < NUMERO_ESTADISTICAS; x++)
            cout << " | " << setw(6) << (int)matriz[y][x];

        float total = matriz[y][NUMERO_ESTADISTICAS];
        cout << " | " << setw(5) << fixed << setprecision(0) << total << endl;

        totalGeneral += total;

        if (total > maxTotal) {
            maxTotal = total;
            strcpy(mejorJugador, jugadores[y]);
        }
        if (total < minTotal) {
            minTotal = total;
            strcpy(peorJugador, jugadores[y]);
        }
        imprimirMatrizLinea();
    }

    float promedioEquipo = totalGeneral / NUMERO_JUGADORES;
    cout << "\nMejor Jugador: " << mejorJugador << " (Total: " << maxTotal << ")" << endl;
    cout << "Peor Jugador : " << peorJugador << " (Total: " << minTotal << ")" << endl;
    cout << "Promedio Equipo: " << fixed << setprecision(2) << promedioEquipo << endl;

    return promedioEquipo;
}

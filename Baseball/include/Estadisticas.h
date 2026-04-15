#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

// Constantes de la clase
#define NUMERO_JUGADORES 5
#define NUMERO_ESTADISTICAS 4
#define MAXIMA_LONGITUD_CADENA 100

class Estadisticas
{
    public:
        Estadisticas();
        virtual ~Estadisticas();

        // Métodos públicos
        int busquedaAleatorios(int minimo, int maximo);
        void llenarMatriz(float matriz[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1]);
        void imprimirMatrizLinea();
        float imprimirMatriz(float matriz[NUMERO_JUGADORES][NUMERO_ESTADISTICAS + 1],
                             char jugadores[NUMERO_JUGADORES][MAXIMA_LONGITUD_CADENA],
                             const char* nombreEquipo);

    private:
        // Constantes privadas
        static const int MIN_ESTADISTICA = 0;
        static const int MAX_HITS = 200;
        static const int MIN_HITS = 40;
        static const int MAX_CARRERAS = 150;
        static const int MIN_CARRERAS = 20;
        static const int MAX_HR = 50;
        static const int MIN_HR = 0;
        static const int MAX_RBI = 130;
        static const int MIN_RBI = 10;
};

#endif // ESTADISTICAS_H

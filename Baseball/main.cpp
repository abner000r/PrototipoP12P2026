#include "../include/imprimirEquipos.h"
#include <cstdlib>  // Para srand() y rand()
#include <ctime>    // Para time()

using namespace std;

int main()
{
    srand(time(NULL));
    imprimirEquipos equipo;
    equipo.llamaCiclo();
    return 0;
}

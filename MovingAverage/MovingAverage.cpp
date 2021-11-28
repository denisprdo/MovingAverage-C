#include <iostream>
#include "MovingAverage.h"

using namespace std;

int main()
{
    MovingAverage moveaverage;

    //--------------------------------------------------
    //Médias Móveis Simples de 5, 10 e 15

    int mm1[3] = { 5, 10, 15 };
    moveaverage.CalcularMediaSimples(3, mm1);

    //--------------------------------------------------
    //Médias Móveis Exponenciais de 5, 10 e 15

    int mm2[3] = { 5, 10, 15 };
    moveaverage.CalcularMediaExponen(3, mm2);

    //--------------------------------------------------
    //Cruzamento de Médias Móveis Simples de 5, 10

    moveaverage.CalcularCruzSimples(5, 10);
    
    //--------------------------------------------------
    //Cruzamento de Médias Móveis Exponenciais de 8, 10

    moveaverage.CalcularCruzExponen(8, 10);

    //--------------------------------------------------

    return 0;
}

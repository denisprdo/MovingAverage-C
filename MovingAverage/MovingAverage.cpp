#include <iostream>
#include "ClassFunctions.h"

using namespace std;

int main()
{
    MovingAverage moveaverage;

    //--------------------------------------------------
    //Médias Móveis Simples de 5, 10 e 15

    int mm1[3] = { 5, 10, 15 };
    int len1 = sizeof(mm1) / sizeof(mm1[0]);

    moveaverage.CalcularMediaSimples(len1, mm1);

    //--------------------------------------------------
    //Médias Móveis Exponenciais de 5, 10 e 15

    int mm2[3] = { 5, 10, 15 };
    int len2 = sizeof(mm2) / sizeof(mm2[0]);

    moveaverage.CalcularMediaExponen(len2, mm2);

    //--------------------------------------------------
    //Cruzamento de Médias Móveis Simples de 5, 10

    moveaverage.CalcularCruzSimples(5, 10);
    
    //--------------------------------------------------
    //Cruzamento de Médias Móveis Exponenciais de 8, 10

    moveaverage.CalcularCruzExponen(8, 10);

    //--------------------------------------------------
    //--------------------------------------------------

    return 0;
}

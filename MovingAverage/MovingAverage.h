#include <iostream>
#include <iomanip>

using namespace std;

class MovingAverage
{
public:
    MovingAverage();
    ~MovingAverage();

    typedef enum { mms, mme } Nm_media;

    void CalcularMediaSimples(int num, int periodo[]);
    void CalcularMediaExponen(int num, int periodo[]);
    void CalcularCruzSimples(int periodo1, int periodo2);
    void CalcularCruzExponen(int periodo1, int periodo2);

private:
    string*                 timevalues;
    double*                 closevalues;

    double**                arrayMMS;
    double**                arrayMME;
    int*                    arrayMMSTittle;
    int*                    arrayMMETittle;

    int                     nRow;
    int                     nMMS;
    int                     nMME;

    void                    SampleMoveAverage(int num, int periodo[]);
    void                    ExponeMoveAverage(int num, int periodo[]);
    void                    MostrarResultados(Nm_media valor);
    void                    MostrarCruzamento(Nm_media valor);
};

                            MovingAverage::MovingAverage()
{
    //Ibovespa (IBOV) 09/08/2021 à 19/10/2021

    this->nRow = 50;

    double* values1 = new double[this->nRow];
    string* values2 = new string[this->nRow];

    this->closevalues= values1;
    this->timevalues = values2;

    this->closevalues[0] = 123.019;		        this->timevalues[0] = "09.08.2021";
    this->closevalues[1] = 122.202;		        this->timevalues[1] = "10.08.2021";
    this->closevalues[2] = 122.056;		        this->timevalues[2] = "11.08.2021";
    this->closevalues[3] = 120.701;		        this->timevalues[3] = "12.08.2021";
    this->closevalues[4] = 121.194;		        this->timevalues[4] = "13.08.2021";
    this->closevalues[5] = 119.18;		        this->timevalues[5] = "16.08.2021";
    this->closevalues[6] = 117.904;		        this->timevalues[6] = "17.08.2021";
    this->closevalues[7] = 116.643;		        this->timevalues[7] = "18.08.2021";
    this->closevalues[8] = 117.165;		        this->timevalues[8] = "19.08.2021";
    this->closevalues[9] = 118.053;		        this->timevalues[9] = "20.08.2021";
    this->closevalues[10] = 117.472;		    this->timevalues[10] = "23.08.2021";
    this->closevalues[11] = 120.211;		    this->timevalues[11] = "24.08.2021";
    this->closevalues[12] = 120.818;		    this->timevalues[12] = "25.08.2021";
    this->closevalues[13] = 118.724;		    this->timevalues[13] = "26.08.2021";
    this->closevalues[14] = 120.678;		    this->timevalues[14] = "27.08.2021";
    this->closevalues[15] = 119.74;		        this->timevalues[15] = "30.08.2021";
    this->closevalues[16] = 118.781;		    this->timevalues[16] = "31.08.2021";
    this->closevalues[17] = 119.396;		    this->timevalues[17] = "01.09.2021";
    this->closevalues[18] = 116.677;		    this->timevalues[18] = "02.09.2021";
    this->closevalues[19] = 116.933;		    this->timevalues[19] = "03.09.2021";
    this->closevalues[20] = 117.869;		    this->timevalues[20] = "06.09.2021";
    this->closevalues[21] = 113.413;		    this->timevalues[21] = "08.09.2021";
    this->closevalues[22] = 115.361;		    this->timevalues[22] = "09.09.2021";
    this->closevalues[23] = 114.286;		    this->timevalues[23] = "10.09.2021";
    this->closevalues[24] = 116.404;		    this->timevalues[24] = "13.09.2021";
    this->closevalues[25] = 116.181;		    this->timevalues[25] = "14.09.2021";
    this->closevalues[26] = 115.063;		    this->timevalues[26] = "15.09.2021";
    this->closevalues[27] = 113.794;		    this->timevalues[27] = "16.09.2021";
    this->closevalues[28] = 111.439;		    this->timevalues[28] = "17.09.2021";
    this->closevalues[29] = 108.844;		    this->timevalues[29] = "20.09.2021";
    this->closevalues[30] = 110.25;		        this->timevalues[30] = "21.09.2021";
    this->closevalues[31] = 112.282;		    this->timevalues[31] = "22.09.2021";
    this->closevalues[32] = 114.064;		    this->timevalues[32] = "23.09.2021";
    this->closevalues[33] = 113.283;		    this->timevalues[33] = "24.09.2021";
    this->closevalues[34] = 113.583;		    this->timevalues[34] = "27.09.2021";
    this->closevalues[35] = 110.124;		    this->timevalues[35] = "28.09.2021";
    this->closevalues[36] = 111.107;		    this->timevalues[36] = "29.09.2021";
    this->closevalues[37] = 110.979;		    this->timevalues[37] = "30.09.2021";
    this->closevalues[38] = 112.9;		        this->timevalues[38] = "01.10.2021";
    this->closevalues[39] = 110.393;		    this->timevalues[39] = "04.10.2021";
    this->closevalues[40] = 110.458;		    this->timevalues[40] = "05.10.2021";
    this->closevalues[41] = 110.56;		        this->timevalues[41] = "06.10.2021";
    this->closevalues[42] = 110.585;		    this->timevalues[42] = "07.10.2021";
    this->closevalues[43] = 112.833;		    this->timevalues[43] = "08.10.2021";
    this->closevalues[44] = 112.18;		        this->timevalues[44] = "11.10.2021";
    this->closevalues[45] = 113.456;		    this->timevalues[45] = "13.10.2021";
    this->closevalues[46] = 113.185;		    this->timevalues[46] = "14.10.2021";
    this->closevalues[47] = 114.648;		    this->timevalues[47] = "15.10.2021";
    this->closevalues[48] = 114.428;		    this->timevalues[48] = "18.10.2021";
    this->closevalues[49] = 110.673;		    this->timevalues[49] = "19.10.2021";
};
                            MovingAverage::~MovingAverage()
{
    free(arrayMMS);
    free(arrayMME);
};

void                        MovingAverage::CalcularMediaSimples(int num, int periodos[])
{
    this->SampleMoveAverage(num, periodos);

    MostrarResultados(Nm_media::mms);
}
void                        MovingAverage::CalcularMediaExponen(int num, int periodos[])
{
    this->ExponeMoveAverage(num, periodos);

    MostrarResultados(Nm_media::mme);
}
void                        MovingAverage::CalcularCruzSimples(int periodo1, int periodo2)
{
    int mm1[2] = { periodo1, periodo2 };

    this->SampleMoveAverage(2, mm1);

    MostrarCruzamento(Nm_media::mms);
}
void                        MovingAverage::CalcularCruzExponen(int periodo1, int periodo2)
{
    int mm1[2] = { periodo1, periodo2 };

    this->ExponeMoveAverage(2, mm1);

    MostrarCruzamento(Nm_media::mme);
}

void                        MovingAverage::MostrarResultados(Nm_media valor)
{
    setlocale(LC_ALL, "");
    cout << fixed;
    cout.precision(4);

    if (valor == Nm_media::mms)
        cout << endl << setw(40) << "Médias Móveis Simples - Ibovespa (IBOV) 09/08/2021 à 19/10/2021";

    if (valor == Nm_media::mme)
        cout << endl << setw(40) << "Médias Móveis Exponenciais - Ibovespa (IBOV) 09/08/2021 à 19/10/2021";

    cout << endl << endl;
    cout << setw(10) << "Índice";
    cout << setw(20) << "Data";
    cout << setw(20) << "Valor";

    cout << endl;
    cout << endl;
    cout << setw(10) << "-----";
    cout << setw(20) << "-----";
    cout << setw(20) << "Períodos->";

    if (valor == Nm_media::mms)
    {
        for (int n = 0; n < this->nMMS; n++)
            cout << setw(20) << this->arrayMMSTittle[n];
    }

    if (valor == Nm_media::mme)
    {
        for (int n = 0; n < this->nMME; n++)
            cout << setw(20) << this->arrayMMETittle[n];
    }

    cout << endl;
    cout << endl;

    for (int j = 0; j < this->nRow; j++)
    {
        cout << setw(10) << j + 1;
        cout << setw(20) << this->timevalues[j];
        cout << setw(20) << this->closevalues[j];

        if (valor == Nm_media::mms)
        {
            for (int n = 0; n < this->nMMS; n++)
                cout << setw(20) << this->arrayMMS[j][n];

            cout << endl;
        }

        if (valor == Nm_media::mme)
        {
            for (int n = 0; n < this->nMME; n++)
                cout << setw(20) << this->arrayMME[j][n];

            cout << endl;
        }
    }
}
void                        MovingAverage::MostrarCruzamento(Nm_media valor)
{
    setlocale(LC_ALL, "");
    cout << fixed;
    cout.precision(4);

    if (valor == Nm_media::mms)
        cout << endl << setw(40) << "Médias Móveis Simples - Ibovespa (IBOV) 09/08/2021 à 19/10/2021";

    if (valor == Nm_media::mme)
        cout << endl << setw(40) << "Médias Móveis Exponenciais - Ibovespa (IBOV) 09/08/2021 à 19/10/2021";

    cout << endl << endl;
    cout << setw(10) << "Índice";
    cout << setw(20) << "Data";
    cout << setw(20) << "Valor";

    cout << endl;
    cout << endl;
    cout << setw(10) << "-----";
    cout << setw(20) << "-----";
    cout << setw(20) << "Períodos->";

    if (valor == Nm_media::mms)
    {
        for (int n = 0; n < this->nMMS; n++)
            cout << setw(20) << this->arrayMMSTittle[n];
    }

    if (valor == Nm_media::mme)
    {
        for (int n = 0; n < this->nMME; n++)
            cout << setw(20) << this->arrayMMETittle[n];
    }

    cout << setw(20) << "Cruzamento";

    cout << endl;
    cout << endl;

    for (int j = 0; j < this->nRow; j++)
    {
        cout << setw(10) << j + 1;
        cout << setw(20) << this->timevalues[j];
        cout << setw(20) << this->closevalues[j];

        if (valor == Nm_media::mms)
        {
            for (int n = 0; n < this->nMMS; n++)
                cout << setw(20) << this->arrayMMS[j][n];

            if (j > 0 && this->arrayMMS[j - 1][0] > 0 && this->arrayMMS[j - 1][1] > 0 && (
                (this->arrayMMS[j][0] > this->arrayMMS[j][1] && this->arrayMMS[j - 1][0] < this->arrayMMS[j - 1][1]) ||
                (this->arrayMMS[j][0] < this->arrayMMS[j][1] && this->arrayMMS[j - 1][0] > this->arrayMMS[j - 1][1])
                ))
            {
                cout << setw(20) << "Cruzou!";
            }
            else
            {
                cout << setw(20) << "-------";
            }

            cout << endl;
        }

        if (valor == Nm_media::mme)
        {
            for (int n = 0; n < this->nMME; n++)
                cout << setw(20) << this->arrayMME[j][n];

            if (j > 0 && this->arrayMME[j - 1][0] > 0 && this->arrayMME[j - 1][1] > 0 && (
                (this->arrayMME[j][0] > this->arrayMME[j][1] && this->arrayMME[j - 1][0] < this->arrayMME[j - 1][1]) ||
                (this->arrayMME[j][0] < this->arrayMME[j][1] && this->arrayMME[j - 1][0] > this->arrayMME[j - 1][1])
                ))
            {
                cout << setw(20) << "Cruzou!";
            }
            else
            {
                cout << setw(20) << "-------";
            }

            cout << endl;
        }
    }
}
void                        MovingAverage::SampleMoveAverage(int num, int periodos[])
{
    double valor;

    this->nMMS = num;
    this->arrayMMSTittle = periodos;

    double** masvalues = new double* [this->nRow];

    for (int i = 0; i < this->nRow; ++i)
    {
        masvalues[i] = new double[this->nMMS];

        for (int n = 0; n < this->nMMS; n++)
        {
            masvalues[i][n] = 0.1;
        }
    }

    this->arrayMMS = masvalues;

    for (int n = 0; n < this->nMMS; n++)
    {
        for (int j = 0; j < this->nRow; j++)
        {
            if (j + 1 >= periodos[n])
            {
                valor = 0;

                for (int i = j - periodos[n] + 1; i <= j; i++)
                {
                    valor += this->closevalues[i];
                };

                valor /= periodos[n];
            }
            else
            {
                valor = 0;
            }

            masvalues[j][n] = valor;
        };
    }
};
void                        MovingAverage::ExponeMoveAverage(int num, int periodos[])
{
    double valor0 = 0;
    double valor1 = 0;
    double valor2 = 0;
    double valor3 = 0;

    this->nMME = num;
    this->arrayMMETittle = periodos;

    double** maevalues = new double* [this->nRow];

    for (int i = 0; i < this->nRow; ++i)
    {
        maevalues[i] = new double[this->nMME];

        for (int n = 0; n < this->nMME; n++)
        {
            maevalues[i][n] = 0.1;
        }
    }

    this->arrayMME = maevalues;

    for (int n = 0; n < this->nMME; n++)
    {
        for (int j = 0; j < this->nRow; j++)
        {
            if (j + 1 == periodos[n])
            {
                valor0 = 0;

                for (int i = j - periodos[n] + 1; i <= j; i++)
                {
                    valor0 += this->closevalues[i];
                };

                valor0 /= periodos[n];
            }
            else if (j + 1 > periodos[n])
            {
                valor1 = (2.0 / (periodos[n] + 1.0));
                valor2 = this->closevalues[j];
                valor3 = maevalues[j - 1][n];

                valor0 = valor1 * (valor2 - valor3) + valor3;
            }
            else
            {
                valor0 = 0;
            }

            maevalues[j][n] = valor0;
        };
    }
};
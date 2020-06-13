#include "MiniDB.h"

//----------------------------------------------------------
//TODO: no es mucho pero es tranajo honesto  ):
//---------------------------------------------------------
//15 min mas y terminaba lo de los caracteres profe  ):

int main()
{
    MiniDB dbupc;
    int primerarespuesta;
    cout << "Que desa hacer? \n 1) Filtrar por fila numerica. \n 2) Filtrar por Indice cararteristico: ";
    cin >> primerarespuesta;

    system("cls");

    if (primerarespuesta == 1)
    {
        int respu;

        int numerocriterio;
        //por fin me salio csm despues de 20 depreciones
        cout << "Ingrese el indice de lo que desea hacer: \n 1) Filtrar mayor a \n 2) Filtrar Menor a \n 3) Filtrar igual a \n";
        cin >> respu;
        system("cls");
        cout << "Ingrese valor: ";
        cin >> numerocriterio;

        auto Graterthan = [numerocriterio, respu](long long x) {
        if (respu <1 || respu > 3)
        {
            return false;
        }
        else if (respu == 1)
        {
            return (x> numerocriterio) ? true : false;
        }
        else if (respu == 2)
        {
            return (x< numerocriterio) ? true : false;
        }
        else if (respu == 3)
        {
            return (x==numerocriterio) ? true : false;
        }
          ; };
        dbupc.getpopulation(Graterthan);
    }

    else if (primerarespuesta == 2)
    {
        int ans;
        string answ;

        cout << "Ingrese el indice de lo que desea hacer: \n 1) Inicia con \n 2) Finaliza con  \n 3) Esta contenido \n";
        cin >> ans;

        system("cls");
        cout << "Ingrese caracter: \n";
        cin >> answ;

        auto Continent = [ans, answ](string c) {
            if (ans < 1 || ans > 3)
            {
                return false;
            }
            else if (ans == 1)
            {

                return (answ[0] == c[0]) ? true : false;
            }
            else if (ans == 2)
            {
                char a;
                return (answ[0] == c[c.size() - 1]) ? true : false;
            }
            else if (ans == 3)
            {
                return (c.find(answ) != string::npos) ? true : false;
            }
        };
        dbupc.getContinet(Continent);
    }
    else if (primerarespuesta==3)
    {
        dbupc.HashWhitPopulation();
        
    }

    dbupc.ShowValues();
    cin.get();
    return 0;
}
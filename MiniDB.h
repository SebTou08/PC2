#ifndef __MINIDB_H__
#define __MINIDB_H__
#include "DobleLinkedList.h"
#include "BinaryTree.h"
#include <fstream>
#include "Hash.hpp"
#include <sstream>
using namespace std;

class MiniDB
{
    ifstream archivo;
    HashTable<int, long long> *MyHash = new HashTable<int, long long>();
    DobleLinkedList<DobleLinkedList<string>> minidb;
    string cadena;
    BinaryTree<DobleLinkedList<DobleLinkedList<string>> *> *IndexTree;

public:
    MiniDB()
    {

        IndexTree = new BinaryTree<DobleLinkedList<DobleLinkedList<string>> *>;
    }
    void reading(string nombre, char ans)
    {
        archivo.open(nombre);
        while (getline(archivo, cadena))
        {
            stringstream ss(cadena);
            if (ans == 's')
                cout << cadena << endl;
            divideField(ss);
        }
    }

    void divideField(istream &registro)
    {
        DobleLinkedList<string> fila;
        string tmp;
        while (getline(registro, tmp, ';'))
        {
            fila.FinalAddition(tmp);
        }
        minidb.FinalAddition(fila);
    }

    void getContinet(function<bool(string c)> PrintCritery)
    {

        ifstream population("covid.csv");
        string registro, a, b, c, d;
        string popu;
        DobleLinkedList<string> fila;
        int p;

        while (getline(population, registro))
        {
            stringstream ss(registro);
            getline(ss, a, ';');
            getline(ss, b, ';');

            if (PrintCritery(b))
            {
                cout << b << endl;
            }
            getline(ss, c, ';');
            getline(ss, d, ';');
            getline(ss, popu, '\n');

            fila.FinalAddition(popu);
        }
        minidb.FinalAddition(fila);
    }

    void HashWhitPopulation()
    {
        ifstream population("covid.csv");
        string registro, a, b, c, d;
        string popu;
        DobleLinkedList<string> fila;
        int p;
        int cont=1;

        while (getline(population, registro))
        {
            stringstream ss(registro);
            getline(ss, a, ';');
            getline(ss, b, ';');
            getline(ss, c, ';');
            getline(ss, d, ';');
            getline(ss, popu, '\n');
            p = stoll(popu, nullptr, 10);
            MyHash->Insert(cont,p);     
            fila.FinalAddition(popu);
            ++cont;

        }
        cout<<"numeros: "<<MyHash->getco();
        minidb.FinalAddition(fila);
    }
    void getpopulation(function<bool(long long x)> criterio)
    {
        ifstream population("covid.csv");
        string registro, a, b, c, d;
        string popu;
        DobleLinkedList<string> fila;
        int p;

        while (getline(population, registro))
        {
            stringstream ss(registro);
            getline(ss, a, ';');
            getline(ss, b, ';');
            getline(ss, c, ';');
            getline(ss, d, ';');
            getline(ss, popu, '\n');
            p = stoll(popu, nullptr, 10);
            if (criterio(p))
            {
                cout << popu << endl;
            }

            fila.FinalAddition(popu);
        }
        minidb.FinalAddition(fila);
    }

    void ShowValues()
    {
        cout << endl
             << "Cantidad de columnas: " << minidb.getsize() << endl;
        //TODO:  cout<<endl<<"Cantidad de columnas: "<<minidb[0].getsize()<<endl;
    }
};

#endif

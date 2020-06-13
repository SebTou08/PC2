#ifndef __DOBLELINKEDLIST_H__
#define __DOBLELINKEDLIST_H__

#include <iostream>
#include <sstream>

#include <stdlib.h>
#include <ctime>
#include <functional>
#include <string>
#include <fstream>
#include <iomanip>
#include "Node.h"
using namespace std;

template <typename TipoGen>
class DobleLinkedList
{
    Node<TipoGen> *beginning;
    Node<TipoGen> *end;
    int size;

public:
    DobleLinkedList()
    {
        beginning = end = nullptr;
        size = 0;
    }

    //METODOS PARA AGREGAR
    void BeginningAddition(TipoGen v)
    {
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        if (size == 0)
        {
            beginning = end = _new;
        }
        else
        {
            _new->ChildRight = beginning;
            beginning->ChildLeft = _new;
            beginning = _new;
        }
        ++size;
    }

    void FinalAddition(TipoGen v)
    {
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        if (size == 0)
        {
            beginning = end = _new;
        }
        else
        {
            end->ChildRight = _new;
            _new->ChildLeft = end;
            end = _new;
        }
        ++size;
    }

    void MiddleAddition(TipoGen v, int p)
    {
        Node<TipoGen> *aux = beginning;
        Node<TipoGen> *_new = new Node<TipoGen>(v);
        for (size_t i = 0; i < p - 1; ++i)
        {
            aux = aux->ChildRight;
        }

        _new->ChildRight = aux->ChildRight;
        _new->ChildLeft = aux;
        aux->ChildRight->ChildLeft = _new;
        aux->ChildRight = _new;
        ++size;
    }

    //ELIMINACION
    void BeginningDisposal()
    {
        Node<TipoGen> *aux = beginning;
        beginning = aux->ChildRight;
        delete aux;
        --size;
    }

    void FinalDisposal()
    {
        Node<TipoGen> *aux = end->ChildLeft;
        delete aux->ChildRight;
        aux->ChildRight = nullptr;
        end = aux;
        --size;
    }


    int getsize() { return size; }


};

#endif // !__DOBLELINKEDLIST_H__

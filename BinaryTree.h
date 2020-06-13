#ifndef __TREE_H__
#define __TREE_H__

#include <iostream>
#include <string>
#include <functional>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Node.h"
#include <stdlib.h>
#include <algorithm>

using namespace std;


template <typename TypeGen>
class BinaryTree
{
private:
	Node<TypeGen> *root;



	void add(Node<TypeGen> *&node, TypeGen data, function<bool(TypeGen)> AddCritery)
	{
		if (node == nullptr)
		{
			node = new Node<TypeGen>(data);
		}
		else
		{
			if (AddCritery(data))
				add(node->ChildRight, data, AddCritery);
			else
				add(node->ChildLeft, data, AddCritery);
		}
	}

	//Ways
	//to
	//print
	//------------------------------------------------------------------------------------
	void inorder(Node<TypeGen> *node, function<void(TypeGen)> PrintCritery)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			inorder(node->ChildLeft, PrintCritery);
			PrintCritery(node->data);
			inorder(node->ChildRight, PrintCritery);
		}
	}

	void printthrown(Node<TypeGen> *bt, int spaces, function<void(TypeGen)> PrintCritery)
	{
		if (bt != NULL)
		{
			printthrown(bt->ChildRight, spaces + 5, PrintCritery);
			for (int i = 0; i < spaces; i++)
				cout << ' ';
			PrintCritery(bt->data); //cout << "   " << bt->g << endl;
			printthrown(bt->ChildLeft, spaces + 5, PrintCritery);
		}
	}

//TODO: probar si funciona mostrar solo los hijos de la izquierda
	void printleft(Node<TypeGen> *node, function<void(TypeGen)> PrintCritery)
	{
		if (node == nullptr)
		{
			return;
		}
		else
		{
			printleft(node->ChildLeft, PrintCritery);
			PrintCritery(node->data);
		}
	}

public:
	BinaryTree() { root = nullptr; }
	void Add(TypeGen data, function<bool(TypeGen)> AddCritery) { add(root, data, AddCritery); }
	void InOrder(function<void(TypeGen)> PrintCritery) { inorder(root, PrintCritery); }
	void PrintLeft(function<void(TypeGen)> PrintCritery) { printleft(root, PrintCritery); }
	void PrintThrown(function<void(TypeGen)> PrintCritery) { printthrown(root, 1, PrintCritery); }

};

#endif
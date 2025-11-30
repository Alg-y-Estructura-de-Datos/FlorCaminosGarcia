/*Unir lista circular con lista simple*/
#include <iostream>
#include "Lista/Lista.h"
#include "Lista/CircList.h"

using namespace std;

void unirListas(CircList<int> &listaCircular, Lista<int> &listaSimple)
{
    int tamanioCircular = listaCircular.getTamanio();

    // Agregar elementos de la lista circular a la lista simple
    for (int i = 0; i < tamanioCircular; i++)
    {
        listaSimple.insertarUltimo(listaCircular.getDato(i));
    }
}

int main()
{
    CircList<int> listaCircular;
    Lista<int> listaSimple;

    // Llenar la lista circular
    listaCircular.insertarUltimo(10);
    listaCircular.insertarUltimo(20);
    listaCircular.insertarUltimo(30);

    // Llenar la lista simple
    listaSimple.insertarUltimo(1);
    listaSimple.insertarUltimo(2);
    listaSimple.insertarUltimo(3);

    cout << "Lista Simple antes de unir:" << endl;
    listaSimple.print();

    unirListas(listaCircular, listaSimple);

    cout << "Lista Simple despues de unir con Lista Circular:" << endl;
    listaSimple.print();

    return 0;
}
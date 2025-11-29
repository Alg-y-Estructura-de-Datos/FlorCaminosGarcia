/*Rotar lista circular K posiciones*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int elemento, k;

    cout << "ROTAR LISTA CIRCULAR K POSICIONES" << endl;
    cout << "Ingrese elementos (0 para terminar): ";

    while (cin >> elemento && elemento != 0)
    {
        lista.insertarUltimo(elemento);
    }

    cout << "Ingrese el numero de posiciones a rotar (k): ";
    cin >> k;

    int tamanio = lista.getTamanio();
    if (tamanio == 0)
    {
        cout << "La lista esta vacia." << endl;
        return 0;
    }

    k = k % tamanio; // Asegurar que k no sea mayor que el tamaño de la lista

    for (int i = 0; i < k; ++i)
    {
        int primerElemento = lista.getDato(0);
        lista.remover(0);
        lista.insertarUltimo(primerElemento);
    }

    cout << "\nLista despues de rotar " << k << " posiciones:" << endl;
    lista.imprimir();

    return 0;
}
/*Rotar lista doble K posiciones*/
#include <iostream>
#include "Lista/ListaDoble.h"

using namespace std;

template <class T>
void rotarListaDoble(ListaDoble<T> &lista, int k)
{
    int tamanio = lista.getTamanio();
    if (tamanio == 0 || k % tamanio == 0)
        return;

    k = k % tamanio; // Asegurar que k esté dentro del tamaño de la lista

    for (int i = 0; i < k; i++)
    {
        T dato = lista.getDato(0);
        lista.remover(0);
        lista.insertarUltimo(dato);
    }
}

int main()
{
    ListaDoble<int> lista;
    int elementos, k;

    cout << "Ingrese los elementos de la lista doble (termina con 0): " << endl;

    while (true)
    {
        cout << "Elemento: ";
        cin >> elementos;

        if (elementos == 0)
            break;

        lista.insertarUltimo(elementos);
    }

    cout << "Lista original: ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    cout << "Ingrese el numero de posiciones a rotar (k): ";
    cin >> k;

    rotarListaDoble(lista, k);

    cout << "Lista despues de rotar " << k << " posiciones: ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    return 0;
}
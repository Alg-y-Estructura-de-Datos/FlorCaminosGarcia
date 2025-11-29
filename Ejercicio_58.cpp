/*Ordenar lista usando bubble sort*/
#include <iostream>
#include "Lista/Lista.h"
#include "Algoritmos Ordenamiento/bubbleSort.h"

using namespace std;

template <class T>
void ordenarListaBubble(Lista<T> &lista)
{
    int n = lista.getTamanio();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lista.getDato(j) > lista.getDato(j + 1))
            {
                T temp = lista.getDato(j);
                lista.reemplazar(j, lista.getDato(j + 1));
                lista.reemplazar(j + 1, temp);
            }
        }
    }
}

int main()
{
    Lista<int> lista;
    int cantidad, elemento;

    cout << "Cuantos elementos desea agregar a la lista? ";
    cin >> cantidad;

    if (cantidad <= 0)
    {
        cout << "La cantidad debe ser mayor a 0." << endl;
        return 1;
    }

    cout << "\nIngrese " << cantidad << " elementos:" << endl;

    for (int i = 0; i < cantidad; i++)
    {
        cout << "Elemento " << (i + 1) << ": ";

        if (!(cin >> elemento))
        {
            cout << "Error: Entrada no válida." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            i--;
            continue;
        }

        lista.insertarUltimo(elemento);
    }

    cout << "\n---RESULTADOS---" << endl;
    cout << "Lista original:" << endl;

    lista.print();
    
    ordenarListaBubble(lista);

    cout << "Lista ordenada (Bubble Sort):" << endl;
    lista.print();

    if (lista.getTamanio() > 0)
    {
        cout << "El menor elemento es: " << lista.getDato(0) << endl;
        cout << "El mayor elemento es: " << lista.getDato(lista.getTamanio() - 1) << endl;
    }
    else
    {
        cout << "La lista está vacía." << endl;
    }

    return 0;
}
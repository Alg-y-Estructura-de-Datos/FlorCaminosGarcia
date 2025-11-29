/*Ordenar lista usando insertion sort*/
#include <iostream>
#include "Lista/Lista.h"
#include "Algoritmos Ordenamiento/insertSort.h"

using namespace std;

template <class T>
void ordenarListaInsertSort(Lista<T> &lista)
{
    int tamanio = lista.getTamanio();
    T *arreglo = new T[tamanio];

    for (int i = 0; i < tamanio; i++)
    {
        arreglo[i] = lista.getDato(i);
    }

    insertSort(arreglo, tamanio);

    for (int i = 0; i < tamanio; i++)
    {
        lista.reemplazar(i, arreglo[i]);
    }

    delete[] arreglo;
}

int main()
{
    Lista<int> lista;

    cout << "Ingrese numeros (0 para terminar):" << endl;
    int valor;
    while (true)
    {
        cout << "Valor: ";
        cin >> valor;
        if (valor == 0)
            break;
        lista.insertarUltimo(valor);
    }

    if (lista.esVacia())
    {
        cout << "La lista esta vacia." << endl;
        return 0;
    }


    ordenarListaInsertSort(lista);

    cout << "Lista ordenada:" << endl;

    lista.print();

    return 0;
}

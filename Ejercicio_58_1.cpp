#include <iostream>
#include "Lista/Lista.h"
#include "Algoritmos Ordenamiento/bubbleSort.h"
#include "Algoritmos Ordenamiento/insertSort.h"
#include "Algoritmos Ordenamiento/quickSort.h"

using namespace std;

enum Algoritmo
{
    BUBBLE_SORT,
    INSERT_SORT,
    QUICK_SORT
};

template <class T>
void ordenarLista(Lista<T> &lista, Algoritmo algo)
{
    int tamanio = lista.getTamanio();
    T *arreglo = new T[tamanio];

    // Copiar lista a arreglo
    for (int i = 0; i < tamanio; i++)
    {
        arreglo[i] = lista.getDato(i);
    }

    // Aplicar algoritmo seleccionado
    switch (algo)
    {
    case BUBBLE_SORT:
        bubbleSort(arreglo, tamanio);
        break;
    case INSERT_SORT:
        insertSort(arreglo, tamanio);
        break;
    case QUICK_SORT:
        quickSort(arreglo, 0, tamanio - 1);
        break;
    }

    // Copiar arreglo ordenado de vuelta a la lista
    for (int i = 0; i < tamanio; i++)
    {
        lista.reemplazar(i, arreglo[i]);
    }

    delete[] arreglo;
}

int main()
{
    Lista<int> lista;
    int opcion;

    // Ingresar datos
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

    cout << "\nLista original: ";
    lista.print();

    // Seleccionar algoritmo
    cout << "\nSeleccione algoritmo de ordenamiento:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    Algoritmo algoritmo;
    switch (opcion)
    {
    case 1:
        algoritmo = BUBBLE_SORT;
        break;
    case 2:
        algoritmo = INSERT_SORT;
        break;
    case 3:
        algoritmo = QUICK_SORT;
        break;
    default:
        cout << "Opcion invalida. Usando Bubble Sort." << endl;
        algoritmo = BUBBLE_SORT;
    }

    // Ordenar
    ordenarLista(lista, algoritmo);

    cout << "Lista ordenada: ";
    lista.print();

    return 0;
}
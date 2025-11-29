/*Insertar en posición ordenada (circular)*/
#include <iostream>
#include "Lista/Lista.h"
#include "Lista/CircList.h"

using namespace std;

template <class T>
void insertarOrdenado(CircList<T> &listaCircular, T dato)
{
    if (listaCircular.esVacia())
    {
        listaCircular.insertarPrimero(dato);
        return;
    }

    int tamanio = 0;
    T primerElemento = listaCircular.getDato(0);
    tamanio++;

    // Encontrar el tamaño real de la lista circular
    while (true)
    {
        T elementoActual = listaCircular.getDato(tamanio);
        if (elementoActual == primerElemento)
        {
            break;
        }
        tamanio++;
        if (tamanio > 1000) // Límite por seguridad
        {
            cout << "Advertencia: Limite alcanzado" << endl;
            break;
        }
    }

    // Buscar la posición correcta para insertar
    int posicion = 0;
    while (posicion < tamanio && listaCircular.getDato(posicion) < dato)
    {
        posicion++;
    }

    listaCircular.insertar(dato, posicion);
}

int main()
{
    CircList<int> circular;

    cout << "=== INSERTAR EN LISTA CIRCULAR ORDENADA ===" << endl;

    // Crear lista
    circular.insertarUltimo(10);
    circular.insertarUltimo(30);
    circular.insertarUltimo(50);
    circular.insertarUltimo(70);

    cout << "Lista circular creada con 4 elementos: 10, 30, 50, 70" << endl;

    // Insertar nuevos elementos
    insertarOrdenado(circular, 40);
    insertarOrdenado(circular, 5);
    insertarOrdenado(circular, 80);

    // Vamos a imprimir solo 7 elementos para ver el comportamiento
    cout << "Imprimiendo 7 elementos despues de inserciones:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "Elemento en posicion " << i << ": " << circular.getDato(i) << endl;
    }

    return 0;
}
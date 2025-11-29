#include <iostream>
#include "Lista/Lista.h"
#include "Lista/CircList.h"

using namespace std;

template <class T>
int encontrarTamanioReal(CircList<T> &listaCircular)
{
    if (listaCircular.esVacia())
    {
        cout << "Lista vacia" << endl;
        return 0;
    }

    T primerElemento = listaCircular.getDato(0);
    cout << "Primer elemento: " << primerElemento << endl;
    int posicion = 1;

    // Avanzamos hasta encontrar el primer elemento de nuevo
    while (true)
    {
        cout << "Probando posicion " << posicion << endl;
        T elementoActual = listaCircular.getDato(posicion);
        cout << "Elemento en posicion " << posicion << ": " << elementoActual << endl;
        if (elementoActual == primerElemento)
        {
            break;
        }
        posicion++;

        // Límite por seguridad
        if (posicion > 1000)
        {
            cout << "Advertencia: Limite alcanzado" << endl;
            break;
        }
    }

    return posicion; // Esto es el tamaño real
}

int main()
{
    CircList<int> circular;

    cout << "=== ENCONTRAR TAMANIO DE LISTA CIRCULAR ===" << endl;

    // Crear lista
    circular.insertarUltimo(10);
    circular.insertarUltimo(20);
    circular.insertarUltimo(30);
    circular.insertarUltimo(40);

    cout << "Lista circular creada con 4 elementos" << endl;

    // Vamos a imprimir solo 5 elementos para ver el comportamiento
    cout << "Imprimiendo 5 elementos:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << circular.getDato(i) << " -> ";
    }
    cout << "..." << endl;

    cout << "Llamando a encontrarTamanioReal..." << endl;
    int tamanio = encontrarTamanioReal(circular);

    cout << "\nRESULTADOS:" << endl;
    cout << "Tamanio de la lista: " << tamanio << " elementos" << endl;
    cout << "Inicio del ciclo: posición 0 (SIEMPRE)" << endl;
    cout << "Fin del ciclo: posicion " << (tamanio - 1) << endl;
    cout << "Comportamiento: Ultimo elemento apunta al primero" << endl;

    return 0;
}
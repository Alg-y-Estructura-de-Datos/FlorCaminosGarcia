/*Implementar cola usando dos pilas*/
#include <iostream>
#include "Pila/Pila.h"
#include "Cola/Cola.h"

using namespace std;

template <class T>
void ColaUsandoPilas(Cola<T> &cola, Pila<T> &pila1, Pila<T> &pila2)
{
    // Desencolar todos los elementos de la cola y apilarlos en pila1
    while (!cola.esVacia())
    {
        T dato = cola.desencolar();
        pila1.push(dato);
    }

    // Transferir los elementos de pila1 a pila2 para invertir el orden
    while (!pila1.esVacia())
    {
        T dato = pila1.pop();
        pila2.push(dato);
    }

    // Apilar los elementos de pila2 de nuevo en la cola
    while (!pila2.esVacia())
    {
        T dato = pila2.pop();
        cola.encolar(dato);
    }
}

int main()
{
    Cola<int> cola;
    Pila<int> pila1, pila2;
    int elemento;

    cout << "IMPLEMENTAR COLA USANDO DOS PILAS" << endl;
    cout << "Ingrese elementos para la cola (0 para terminar): ";

    while (cin >> elemento && elemento != 0)
    {
        cola.encolar(elemento);
    }

    ColaUsandoPilas(cola, pila1, pila2);

    cout << "\nElementos en la cola despues de implementar usando dos pilas:" << endl;
    while (!cola.esVacia())
    {
        cout << cola.desencolar() << " ";
    }
    cout << endl;

    return 0;
}

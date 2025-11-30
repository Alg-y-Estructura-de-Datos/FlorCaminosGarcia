/*Ordenar pila usando pila temporal*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void ordenarPila(Pila<int> &pila)
{
    Pila<int> temp;

    do
    {
        int actual = pila.pop();

        while (!temp.esVacia() && temp.pop() > actual)
        {
            pila.push(temp.pop());
        }
        temp.push(actual);
    } while (!pila.esVacia());

    // Transferir de vuelta a la pila original

    while (!temp.esVacia())
    {
        pila.push(temp.pop());
    }
}

int main()
{
    Pila<int> pila;

    // Agregar elementos desordenados
    pila.push(34);
    pila.push(3);
    pila.push(31);
    pila.push(98);
    pila.push(92);
    pila.push(23);

    cout << "Pila original (de tope a base): ";
    Pila<int> copia = pila;
    while (!copia.esVacia())
    {
        cout << copia.pop() << " ";
    }
    cout << endl;

    ordenarPila(pila);

    cout << "Pila ordenada (de tope a base): ";
    while (!pila.esVacia())
    {
        cout << pila.pop() << " ";
    }
    cout << endl;

    return 0;
}

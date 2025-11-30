/*Implementar pila con operación getMin() en O(1)*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void getMinimo(Pila<int> &pila, int &minimo)
{
    Pila<int> aux;
    minimo = INT_MAX;

    while (!pila.esVacia())
    {
        int tope = pila.pop();
        if (tope < minimo)
        {
            minimo = tope;
        }
        aux.push(tope);
    }
    while (!aux.esVacia())
    {
        pila.push(aux.pop());
    }
}

int main()
{
    Pila<int> pila;
    int dato, minimo;

    cout << "Ingrese elementos a la pila (0 para terminar):" << endl;
    while (true)
    {
        cin >> dato;
        if (dato == 0) break;
        pila.push(dato);
    }

    getMinimo(pila, minimo);

    cout << "El minimo elemento de la pila es: " << minimo << endl;

    return 0;
}
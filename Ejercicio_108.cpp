/*Verificar si array puede ser ordenado con pila*/
#include <iostream>
#include <vector>
#include "Pila/Pila.h"

using namespace std;

bool puedeSerOrdenadoConPila( vector<int> &arr)
{
    Pila<int> pila;
    int esperado = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        pila.push(arr[i]);

        while (!pila.esVacia() && pila.pop() == esperado)
        {
            esperado++;
        }
    }

    return esperado - 1 == arr.size();
}

int main()
{
    int n, elemento;

    cout << "Ingrese el numero de elementos: ";
    cin >> n;

    vector<int> arr;
    cout << "Ingrese los elementos del arreglo:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> elemento;
        arr.push_back(elemento);
    }

    if (puedeSerOrdenadoConPila(arr))
    {
        cout << "El arreglo puede ser ordenado usando una pila." << endl;
    }
    else
    {
        cout << "El arreglo no puede ser ordenado usando una pila." << endl;
    }

    return 0;
}

/*Encontrar siguiente elemento mayor*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void encontrarSiguienteMayor(int arr[], int n)
{
    Pila<int> pila;
    int Mayor;

    for (int i = n - 1; i >= 0; i--)
    {
        Mayor = -1;

        while (!pila.esVacia())
        {
            int tope = pila.pop();
            if (tope > arr[i])
            {
                Mayor = tope;
                pila.push(tope); // Volver a apilar el elemento mayor encontrado
                break;
            }
        }

        cout << "Elemento: " << arr[i] << ", Siguiente mayor: " << Mayor << endl;

        pila.push(arr[i]);
    }
}

int main()
{
    int tamanio;

    cout << "Ingrese el tamanio del arreglo: ";
    cin >> tamanio;

    int *arr = new int[tamanio];

    cout << "Ingrese los elementos del arreglo:" << endl;

    for (int i = 0; i < tamanio; i++)
    {
        cin >> arr[i];
    }

    cout << "Resultados:" << endl;

    encontrarSiguienteMayor(arr, tamanio);

    delete[] arr;
    return 0;
}
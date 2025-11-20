/*Encontrar elemento en lista circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int n, dato, pos;

    cout << "Ingrese la cantidad de elementos a agregar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    cout << "Ingrese el elemento a buscar: ";
    cin >> dato;

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        if (lista.getDato(i) == dato)
        {
            pos = i;
            break;
        }
        else
        {
            pos = -1;
        }
    }

    return 0;
}
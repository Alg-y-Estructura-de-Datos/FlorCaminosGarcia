/*Encontrar elemento en lista circular*/
#include <iostream>
#include <vector>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int n, dato;
    vector<int> posiciones;

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
            posiciones.push_back(i);
        }
    }

    if (!posiciones.empty())
    {
        cout << "Elemento encontrado en " << posiciones.size() << " posicion(es): ";
        for (int pos : posiciones)
        {
            cout << pos << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Elemento no encontrado" << endl;
    }

    return 0;
}
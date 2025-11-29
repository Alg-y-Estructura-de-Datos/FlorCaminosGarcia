#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista1, lista2;
    int elemento;

    cout << "COMPARAR DOS LISTAS CIRCULARES" << endl;

    // Primera lista
    cout << "Elementos primera lista (0 para terminar): ";
    while (cin >> elemento && elemento != 0)
    {
        lista1.insertarUltimo(elemento);
    }

    // Segunda lista
    cout << "Elementos segunda lista (0 para terminar): ";
    while (cin >> elemento && elemento != 0)
    {
        lista2.insertarUltimo(elemento);
    }

    // Comparación simple
    cout << "\nLista 1 (" << lista1.getTamanio() << " elementos): ";
    lista1.imprimir();
    cout << "Lista 2 (" << lista2.getTamanio() << " elementos): ";
    lista2.imprimir();

    if (lista1.getTamanio() == lista2.getTamanio())
    {
        cout << "Mismo tamanio - compare visualmente si son iguales" << endl;
    }
    else
    {
        cout << "Diferente tamanio - no pueden ser iguales" << endl;
    }

    return 0;
}
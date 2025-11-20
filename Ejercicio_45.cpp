/*Contar elementos en lista circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int n, dato, contador = 0;

    cout << "Ingrese la cantidad de elementos a agregar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    // Contar elementos en la lista circular
    contador = lista.getTamanio();
    cout << "La cantidad de elementos en la lista circular es: " << contador << endl;

    return 0;
}
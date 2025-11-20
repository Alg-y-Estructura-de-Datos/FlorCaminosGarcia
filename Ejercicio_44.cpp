/*Verificar si lista circular tiene ciclo (siempre true)*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int n, dato;

    cout << "Ingrese la cantidad de elementos a agregar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    // En una lista circular siempre hay ciclo
    cout << "La lista circular siempre tiene ciclo." << endl;

    return 0;
}
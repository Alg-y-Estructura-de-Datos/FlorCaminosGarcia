/*Eliminar por valor en lista circular*/
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

    cout << "Ingrese el elemento a eliminar: ";
    cin >> dato;

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        if (lista.getDato(i) == dato)
        {
            lista.eliminarPorValor(dato);
            cout << "Elemento " << dato << " eliminado de la lista." << endl;
            break;
        }
        else if (i == lista.getTamanio() - 1)
        {
            cout << "Elemento " << dato << " no encontrado en la lista." << endl;
        }
    }

    return 0;
}
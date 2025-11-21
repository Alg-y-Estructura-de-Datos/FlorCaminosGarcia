/*Eliminar por valor en lista circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int n, dato, elemento_eliminar;

    cout << "Ingrese la cantidad de elementos a agregar: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    cout << "\nLista original:" << endl;
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }
    cout << endl;

    cout << "Ingrese el elemento a eliminar: ";
    cin >> elemento_eliminar;

    int contador = 0;
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        if (lista.getDato(i) == elemento_eliminar)
        {
            contador++;
        }
    }

    if (contador > 0)
    {
        for (int i = 0; i < contador; i++)
        {
            lista.eliminarPorValor(elemento_eliminar);
        }
        cout << "Se eliminaron " << contador << " ocurrencias del elemento " << elemento_eliminar << " de la lista." << endl;
    }
    else
    {
        cout << "Elemento " << elemento_eliminar << " no encontrado en la lista." << endl;
    }

    cout << "\nElementos en la lista despues de la eliminacion:" << endl;
    if (lista.getTamanio() > 0)
    {
        for (int i = 0; i < lista.getTamanio(); i++)
        {
            cout << lista.getDato(i) << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "La lista esta vacia." << endl;
    }

    return 0;
}
/*Eliminar K-ésimo elemento continuamente (problema de José)*/
#include <iostream>
#include "Lista/Lista.h"
#include "Lista/CircList.h"

using namespace std;

template <class T>
void eliminarKEsimo(CircList<T> &lista, int k)
{
    if (lista.esVacia() || k <= 0)
        return;

    int index = 0;
    while (lista.getTamanio() > 1)
    {
        index = (index + k - 1) % lista.getTamanio();
        lista.remover(index);
    }
}

int main()
{
    CircList<int> lista;
    int n, k;

    cout << "Ingrese el numero de elementos: ";
    cin >> n;
    cout << "Ingrese el valor de k: ";
    cin >> k;

    for (int i = 1; i <= n; ++i)
    {
        lista.insertarUltimo(i);
    }

    eliminarKEsimo(lista, k);

    cout << "El elemento restante es: " << lista.getDato(0) << endl;

    return 0;
}
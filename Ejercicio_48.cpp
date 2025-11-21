/*Reorganizar una lista en el orden: primer elemento,
último elemento, segundo elemento, penúltimo elemento, etc.*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

void reorganizarLista(CircList<int> &lista)
{
    int n = lista.getTamanio();
    CircList<int> reorganizada;

    for (int i = 0; i < n / 2; i++)
    {
        reorganizada.insertarUltimo(lista.getDato(i));
        reorganizada.insertarUltimo(lista.getDato(n - i - 1));
    }

    if (n % (2) == 1) {
        reorganizada.insertarUltimo(lista.getDato(n / 2));
    }

    while (!lista.esVacia()) {
        lista.remover(0);
    }

    for (int i = 0; i < reorganizada.getTamanio(); i++)
    {
        lista.insertarUltimo(reorganizada.getDato(i));
    }
}

int main()
{
    CircList<int> lista;
    int n, dato;

    cout << "Ingrese la cantidad de elementos para la lista: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    reorganizarLista(lista);

    cout << "Lista reorganizada: ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    return 0;
}
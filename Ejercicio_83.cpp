/*Eliminar todos los elementos con valor X*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    int elementos, x;

    cout << "Ingrese los elementos de la lista (termina con 0): " << endl;

    while (true)
    {
        cout << "Elemento: ";
        cin >> elementos;

        if (elementos == 0)
            break;

        lista.insertarUltimo(elementos);
    }

    cout << "Lista original: ";
    lista.print();

    cout << "Ingrese el valor X a eliminar: ";
    cin >> x;

    for (int i = 0; i < lista.getTamanio();)
    {
        if (lista.getDato(i) == x)
        {
            lista.remover(i);
        }
        else
        {
            i++;
        }
    }

    cout << "Lista despues de eliminar los elementos con valor " << x << ": ";
    lista.print();

    return 0;
}
/*Encontrar elemento mayor en circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int elemento;

    cout << "ENCONTRAR ELEMENTO MAYOR EN LISTA CIRCULAR" << endl;
    cout << "Ingrese elementos (0 para terminar): ";

    while (cin >> elemento && elemento != 0)
    {
        lista.insertarUltimo(elemento);
    }

    if (lista.esVacia())
    {
        cout << "La lista esta vacia." << endl;
    }
    else
    {
        int mayor = lista.getDato(0);
        for (int i = 1; i < lista.getTamanio(); ++i)
        {
            int actual = lista.getDato(i);
            if (actual > mayor)
            {
                mayor = actual;
            }
        }

        cout << "El elemento mayor en la lista circular es: " << mayor << endl;
    }

    return 0;
}
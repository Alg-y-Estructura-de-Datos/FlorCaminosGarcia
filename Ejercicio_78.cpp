// Encontrar primer carácter no repetido
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void encontrarPrimerNoRepetido(const Lista<T> &lista)
{
    if (lista.esVacia())
    {
        throw "La lista esta vacia";
    }

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        T elementoActual = lista.getDato(i);
        bool esRepetido = false;

        for (int j = 0; j < lista.getTamanio(); j++)
        {
            if (i != j && lista.getDato(j) == elementoActual)
            {
                esRepetido = true;
                break;
            }
        }

        if (!esRepetido)
        {
            cout << "El primer elemento no repetido es: " << elementoActual << endl;
            return;
        }
    }

    throw "No hay elementos no repetidos en la lista";
}


int main()
{
    Lista<int> lista;
    int elemento;

    while (true)
    {
        cout << "Ingrese elementos a la lista (0 para terminar): ";
        cin >> elemento;

        if (elemento == 0)
            break;

        lista.insertarUltimo(elemento);
    }

    cout << "Lista ingresada: ";
    lista.print();

    try
    {
        encontrarPrimerNoRepetido(lista);
    }
    catch (const char *mensaje)
    {
        cout << "Error: " << mensaje << endl;
    }

    cout << "Lista final: ";
    lista.print();

    return 0;
}

/*Rotar lista hacia la izquierda*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void rotarLista_aIzquierda(Lista<T> &lista)
{
    if (lista.getTamanio() <= 1)
    {
        return;
    }

    T primerElemento = lista.getDato(0);

    lista.remover(0);

    lista.insertarUltimo(primerElemento);
}

int main()
{
    Lista<int> miLista;
    int num;

    cout << "Ingrese el valor 0 al terminar de ingresar los elementos de la lista" << endl;

    while (true)
    {
        cout << "Ingrese el elemento siguiente de la lista: " << endl;
        cin >> num;

        if (num == 0)
        {
            break;
        }

        miLista.insertarUltimo(num);
    }

    cout << "Lista original: " << endl;
    miLista.print();

    rotarLista_aIzquierda(miLista);

    cout << "Lista Rotada por Izquierda" << endl;
    miLista.print();

    return 0;
}
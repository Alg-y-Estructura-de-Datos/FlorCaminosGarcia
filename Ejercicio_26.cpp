/*Rotar lista hacia la derecha*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void rotarLista_aDerecha(Lista<T> &lista)
{
    if (lista.getTamanio() <= 1)
    {
        return;
    }

    T ultimoElemento = lista.getDato(lista.getTamanio() - 1);

    lista.remover(lista.getTamanio() - 1);

    lista.insertarPrimero(ultimoElemento);
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

    rotarLista_aDerecha(miLista);

    cout << "Lista Rotada por Derecha: " << endl;
    miLista.print();

    return 0;
}
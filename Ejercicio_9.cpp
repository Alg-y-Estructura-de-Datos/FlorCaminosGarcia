/*Invertir una lista*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void invertirLista(Lista<T> &lista)
{
    Lista<T> temp;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        temp.insertarPrimero(lista.getDato(i));
    }

    lista.vaciar();

    for (int i = 0; i < tamanio; i++)
    {
        lista.insertarUltimo(temp.getDato(i));
    }
}

int main()
{
    Lista<int> miLista;

    for (int i = 1; i <= 5; i++)
    {
        miLista.insertarUltimo(i);
    }

    cout << "**LISTA ORIGINAL**" << endl;
    miLista.print();

    invertirLista(miLista);

    cout << "**LISTA INVERTIDA**" << endl;
    miLista.print();

    return 0;
}
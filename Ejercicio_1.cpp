#include <iostream>
#include "Lista/Lista.h"
#include "Pila/Pila.h"

using namespace std;

template <class T>
void invertirLstaConPila(Lista<T> &lista)
{
    Pila<T> pila;
    int size = lista.getTamanio();

    for (int i = 0; i < size; i++)
    {
        pila.push(lista.getDato(i));
    }

    for (int i = 0; i < size; i++)
    {
        lista.reemplazar(i, pila.pop());
    }
}

int main() {
    Lista<int> lista;
    lista.insertarPrimero(1);
    lista.insertar(1,2);
    lista.insertar(2,3);
    lista.insertar(3,4);
    lista.insertarUltimo(5);

    cout<< "Lista Original: ";
    lista.print();

    invertirLstaConPila(lista);

    cout<< "Lista Invertida: ";
    lista.print();

    return 0;
};
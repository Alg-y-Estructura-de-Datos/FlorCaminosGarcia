/*Invertir lista doble*/
#include <iostream>
#include "Lista/ListaDoble.h"

using namespace std;

template <class T>
void invertirListaDoble(ListaDoble<T> &lista)
{
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio / 2; i++)
    {
        T temp = lista.getDato(i);
        lista.reemplazar(i, lista.getDato(tamanio - 1 - i));
        lista.reemplazar(tamanio - 1 - i, temp);
    }
}

int main()
{
    ListaDoble<int> lista;
    int elementos;

    cout << "Ingrese los elementos de la lista doble (termina con 0): " << endl;

    while (true)
    {
        cout << "Elemento: ";
        cin >> elementos;

        if (elementos == 0)
            break;

        lista.insertarUltimo(elementos);
    }

    cout << "Lista original: ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }
    cout << endl;

    invertirListaDoble(lista);

    cout << "Lista invertida: ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }
    cout << endl;

    return 0;
}

/*Unir dos listas dobles ordenadas*/
#include <iostream>
#include "Lista/ListaDoble.h"

using namespace std;

template <class T>
ListaDoble<T> unirListasOrdenadas(const ListaDoble<T> &lista1, const ListaDoble<T> &lista2)
{
    ListaDoble<T> listaUnida;
    int i = 0, j = 0;
    int tamanio1 = lista1.getTamanio();
    int tamanio2 = lista2.getTamanio();

    while (i < tamanio1 && j < tamanio2)
    {
        if (lista1.getDato(i) < lista2.getDato(j))
        {
            listaUnida.insertarUltimo(lista1.getDato(i));
            i++;
        }
        else
        {
            listaUnida.insertarUltimo(lista2.getDato(j));
            j++;
        }
    }

    while (i < tamanio1)
    {
        listaUnida.insertarUltimo(lista1.getDato(i));
        i++;
    }

    while (j < tamanio2)
    {
        listaUnida.insertarUltimo(lista2.getDato(j));
        j++;
    }

    return listaUnida;
}

int main()
{
    ListaDoble<int> lista1, lista2, listaUnida;
    int elementos;

    cout << "Ingrese los elementos de la primera lista doble ordenada (termina con 0): " << endl;

    while (true)
    {
        cout << "Elemento: ";
        cin >> elementos;

        if (elementos == 0)
            break;

        lista1.insertarUltimo(elementos);
    }

    cout << "Ingrese los elementos de la segunda lista doble ordenada (termina con 0): " << endl;

    while (true)
    {
        cout << "Elemento: ";
        cin >> elementos;

        if (elementos == 0)
            break;

        lista2.insertarUltimo(elementos);
    }

    listaUnida = unirListasOrdenadas(lista1, lista2);

    cout << "Lista unida ordenada: ";
    for (int i = 0; i < listaUnida.getTamanio(); i++)
    {
        cout << listaUnida.getDato(i) << " ";
    }
    cout << endl;

    return 0;
}
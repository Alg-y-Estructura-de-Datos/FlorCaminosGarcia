/*Encontrar mediana en lista doble*/
#include <iostream>
#include "Lista/ListaDoble.h"

using namespace std;

template <class T>
T encontrarMediana(const ListaDoble<T> &lista)
{
    int tamanio = lista.getTamanio();
    if (tamanio == 0)
    {
        throw runtime_error("La lista está vacía");
    }

    if (tamanio % 2 == 1)
    {
        return lista.getDato(tamanio / 2);
    }
    else
    {
        T mid1 = lista.getDato(tamanio / 2 - 1);
        T mid2 = lista.getDato(tamanio / 2);
        return (mid1 + mid2) / 2;
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

    cout << "Lista ingresada: ";
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }
    cout << endl;

    try
    {
        double mediana = encontrarMediana(lista);
        cout << "La mediana de la lista es: " << mediana << endl;
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
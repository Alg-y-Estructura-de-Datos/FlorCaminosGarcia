/*Duplicar cada elemento de la lista*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void crearDuplicados(Lista<T> &miLista)
{
    int tamanioOriginal = miLista.getTamanio();

    bool yaEstaDuplicada = true;

    for (int i = 0; i < tamanioOriginal * 2; i += 2)
    {
        if (i + 1 >= miLista.getTamanio() || miLista.getDato(i) != miLista.getDato(i + 1))
        {
            yaEstaDuplicada = false;
            break;
        }
    }

    if (yaEstaDuplicada && tamanioOriginal > 0)
    {
        cout << "La lista ya está duplicada. No se realizarán cambios." << endl;
        return;
    }

    int tamanio = miLista.getTamanio();

    for (int i = 0; i < tamanio * 2; i += 2)
    {
        if (i < miLista.getTamanio())
        {
            T num = miLista.getDato(i);

            if (i + 1 >= miLista.getTamanio() || miLista.getDato(i + 1) != num)
            {
                miLista.insertar(i + 1, num);
            }
        }
    }
}

int main()
{
    Lista<int> lista;
    int num;

    cout << "Ingrese numeros (0 para terminar):" << endl;

    while (true)
    {
        cout << "Ingrese el elemento siguiente a la lista: " << endl;
        cin >> num;

        if (num == 0)
        {
            break;
        }

        lista.insertarUltimo(num);
    }

    cout << "Lista original: " << endl;
    lista.print();

    crearDuplicados(lista);

    cout << "Lista con Duplicados" << endl;
    lista.print();

    return 0;
}
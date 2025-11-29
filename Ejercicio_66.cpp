/*Eliminar duplicados (todos)*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void eliminarDuplicados(Lista<T> &lista)
{
    if (lista.esVacia())
        return;

    Lista<T> listaSinDuplicados;
    int tamanio = lista.getTamanio();

    for (int i = 0; i < tamanio; i++)
    {
        T valorActual = lista.getDato(i);
        bool existe = false;

        for (int j = 0; j < listaSinDuplicados.getTamanio(); j++)
        {
            if (listaSinDuplicados.getDato(j) == valorActual)
            {
                existe = true;
                break;
            }
        }

        if (!existe)
        {
            listaSinDuplicados.insertarUltimo(valorActual);
        }
    }

    lista.vaciar();
    for (int i = 0; i < listaSinDuplicados.getTamanio(); i++)
    {
        lista.insertarUltimo(listaSinDuplicados.getDato(i));
    }
}

int main()
{
    Lista<int> lista;
    int elementos;

    cout << "=== ELIMINADOR DE DUPLICADOS ===" << endl;
    cout << "Ingrese elementos a la lista (0 para terminar):" << endl;

    while (true)
    {
        cout << "Ingrese el elemento a agregar en la lista: " << endl;
        cin >> elementos;

        if (elementos == 0)
        {
            break;
        }

        lista.insertarUltimo(elementos);
    }

    if (lista.esVacia())
    {
        cout << "La lista está vacía." << endl;
        return 0;
    }

    cout << "\n--- LISTA ORIGINAL ---" << endl;
    lista.print();
    cout << "Tamanio: " << lista.getTamanio() << " elementos" << endl;

    cout << "\n--- ELIMINANDO DUPLICADOS ---" << endl;
    eliminarDuplicados(lista);

    cout << " Duplicados eliminados correctamente." << endl;

    cout << "\n--- LISTA SIN DUPLICADOS ---" << endl;
    lista.print();
    cout << "Tamanio: " << lista.getTamanio() << " elementos" << endl;

    return 0;
}
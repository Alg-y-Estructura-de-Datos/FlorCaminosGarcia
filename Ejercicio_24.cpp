/*Eliminar elementos duplicados consecutivos*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void EliminarDuplicados(Lista<T> &miLista)
{
    int tamanio = miLista.getTamanio();

    if (tamanio <= 1)
    {
        return;
    }

    for (int i = miLista.getTamanio() - 2; i >= 0; i--)
    {
        if (miLista.getDato(i) == miLista.getDato(i + 1))
        {
            miLista.remover(i + 1);
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

    EliminarDuplicados(lista);

    cout << "Lista con los duplicados eliminados" << endl;
    lista.print();

    return 0;
}
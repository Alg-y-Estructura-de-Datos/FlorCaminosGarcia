/*Revertir grupos de K elementos*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    Lista<int> lista_r;
    int elementos;
    int grupo;

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

    cout << "Lista Ingresada: " << endl;

    lista.print();

    cout << " Ingresa el numero de elementos por grupo: " << endl;
    cin >> grupo;

    for (int i = 0; i < lista.getTamanio(); i += grupo)
    {
        int fin = i + grupo;

        if (fin > lista.getTamanio())
        {
            fin = lista.getTamanio();
        }

        if (fin - i == grupo)
        {
            for (int j = fin - 1; j >= i; j--)
            {
                lista_r.insertarUltimo(lista.getDato(j));
            }
        }
        else
        {
            for (int j = i; j < fin; j++)
            {
                lista_r.insertarUltimo(lista.getDato(j));
            }
        }
    }

    cout << "Lista con los grupos revertidos: " << endl;

    lista_r.print();

    return 0;
}
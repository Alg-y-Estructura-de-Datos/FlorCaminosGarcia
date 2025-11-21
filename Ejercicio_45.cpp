/*Contar elementos en lista circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int dato, contador = 0;

    while (true)
    {
        cout << "Ingrese el siguiente elemento " << endl;
        cin >> dato;

        if (dato == 0)
        {
            break;
        }

        lista.insertarUltimo(dato);
    }

    // Contar elementos en la lista circular
    contador = lista.getTamanio();
    cout << "La cantidad de elementos en la lista circular es: " << contador << endl;

    cout << "Lista original: " << endl;
    for (int i = 0; i < contador ; i++)
    {
        cout << lista.getDato(i) << endl;
    }
    

    return 0;
}
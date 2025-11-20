/*Eliminar último elemento*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int num;

    cout << "ingresar 0 al terminar de ingresar los valores de la lista: " << endl;

    while (true)
    {
        cout << "Ingrese el siguiente valor de la lista: " << endl;
        cin >> num;

        if (num == 0)
        {
            break;
        }

        miLista.insertarUltimo(num);
    }

    cout << "Lista original: " << endl;
    miLista.print();

    if (miLista.getTamanio() > 0)
    {
        miLista.remover(miLista.getTamanio() - 1);
        cout << " Ultimo elemento eliminado " << endl;
    }

    cout << "Lista modificada: " << endl;
    miLista.print();
    return 0;
}
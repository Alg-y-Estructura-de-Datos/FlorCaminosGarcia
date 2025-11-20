/*Buscar elemento desde el inicio*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int num;
    int elemento_buscado;

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

    cout << "Ingrese el elemento que desea encontrar en lalista: " << endl;
    cin >> elemento_buscado;

    for (int i = 0; i < miLista.getTamanio(); i++)
    {
        if (miLista.getDato(i) == elemento_buscado)
        {
            cout << "Elemento: " << elemento_buscado << " Encontrado en la posicion: " << i << endl;
        }
        else
        {
            cout << "Elemento No encontrado" << endl;
        }
    }

    return 0;
}
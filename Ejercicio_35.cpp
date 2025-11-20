/*Buscar elemento desde el final*/
/*Buscar elemento desde el inicio*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int num;
    int elemento_buscado;
    bool encontrado = false;

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

    cout << "Ingrese el elemento que desea encontrar en la lista: ";
    cin >> elemento_buscado;

    cout << "Buscando desde el final..." << endl;

    for (int i = miLista.getTamanio() - 1; i >= 0; i--)
    {
        cout << "Revisando posicion " << i << ": " << miLista.getDato(i);

        if (miLista.getDato(i) == elemento_buscado)
        {
            cout << "Elemento: " << elemento_buscado << " Encontrado en la posicion: " << i << endl;
        }
        else
        {
            cout << "Elemento No encontrado" << endl;
        }
    }

    if (!encontrado)
    {
        cout << "Elemento no encontrado en ninguna posicion" << endl;
    }

    return 0;
}
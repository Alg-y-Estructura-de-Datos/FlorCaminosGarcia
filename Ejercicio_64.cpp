/*Crear sublista desde posición X a Y*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    Lista<int> sublista;
    int elementos;
    int pos_X, pos_Y;

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

    cout << "Ingrese el valor Inicial (X) de la sublista: " << endl;
    cin >> pos_X;

    cout << "Ingrese el valor final (T) de la sublista: " << endl;
    cin >> pos_Y;

    for (int i = pos_X; i <= pos_Y; i++)
    {
        sublista.insertarUltimo(lista.getDato(i));
    }

    cout << "Sublista creada: " << endl;
    sublista.print();

    return 0;
}
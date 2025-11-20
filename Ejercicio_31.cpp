/*Insertar al final*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int num;
    int ultimo;

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

    cout << "Inserte el ultimo numero que desea colocar al inicio de la lista: " << endl;
    cin >> ultimo;

    miLista.insertarUltimo(ultimo);

    cout << "Lista modificada: " << endl;
    miLista.print();
    return 0;
}
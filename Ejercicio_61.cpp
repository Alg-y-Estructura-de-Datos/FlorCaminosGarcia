/*Encontrar elemento del medio*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    int elemento;
    double medio;

    while (true)
    {
        cout << "Ingrese el elemento a agregar en la lista: " << endl;
        cin >> elemento;

        if (elemento == 0)
        {
            break;
        }

        lista.insertarUltimo(elemento);
    }

    cout << "Lista Ingresada: " << endl;

    lista.print();

    int n = lista.getTamanio();

    if (n == 0)
    {
        throw runtime_error("Lista vacía");
    }

    if (n % 2 != 0)
    {
        medio = lista.getDato(n / 2);
    }
    else
    {
        medio = (lista.getDato(n / 2) + lista.getDato((n / 2) - 1)) / 2.0;
    }

    cout << " El valor del medio en la lista ingresada es: " << medio << endl;
}
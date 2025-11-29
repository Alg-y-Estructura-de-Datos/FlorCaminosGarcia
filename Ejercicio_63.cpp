 /*Insertar elementos en posiciones impares*/
 /*Eliminar elementos en posiciones pares*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> lista;
    int elemento;

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

    for (int i = 0; i < lista.getTamanio(); i++)
    {
        if (lista.getDato(i) % (2) == 0)
        {
            lista.remover(i);
        }
    }

    cout << "Lista con Elementos par eliminados: " << endl;

    lista.print();

    return 0;
}
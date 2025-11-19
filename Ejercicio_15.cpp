/*Verificar si lista está vacía*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;

    miLista.insertarPrimero(1);
    miLista.insertar(1, 2);
    miLista.insertar(2, 3);
    miLista.insertar(3, 4);
    miLista.insertar(4, 5);
    miLista.insertar(5, 6);
    miLista.insertar(6, 7);
    miLista.insertar(7, 8);
    miLista.insertar(8, 9);
    miLista.insertarUltimo(10);

    // miLista.vaciar();

    if (miLista.esVacia())
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        cout << "La lista NO esta vacia" << endl;
    }
}
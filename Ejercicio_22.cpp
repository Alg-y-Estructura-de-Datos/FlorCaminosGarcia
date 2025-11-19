/*Crear lista con números pares del 1-20*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista <int> miLista;

    miLista.insertarPrimero(2);
    miLista.insertar(1, 4);
    miLista.insertar(2, 6);
    miLista.insertar(3, 8);
    miLista.insertar(4, 10);
    miLista.insertar(5, 12);
    miLista.insertar(6, 14);
    miLista.insertar(7, 16);
    miLista.insertar(8, 18);
    miLista.insertarUltimo(20);

    miLista.print();
}
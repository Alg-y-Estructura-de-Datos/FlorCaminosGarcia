/*Crear pila con 5 elementos*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main()
{
    Pila<int> pilaEnteros;
    for (int i = 1; i <= 5; i++)
    {
        pilaEnteros.push(i);
    }
    cout << "Elementos de la pila:" << endl;
    while (!pilaEnteros.esVacia())
    {
        cout << pilaEnteros.pop() << endl;
    }
    return 0;
}
/*Desapilar todos los elementos*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main()
{
    Pila<char> pila;

    pila.push('A');
    pila.push('B');
    pila.push('C');
    pila.push('D');
    pila.push('E');
    pila.push('F');

    while (!pila.esVacia())
    {
        cout << pila.pop() << endl;
    }
}
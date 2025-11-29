//Invertir una Pila utilizando una Pila auxiliar
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

void  invertirPila(Pila<int> &pila)
{
    Pila<int> pilaAuxiliar;
    int elemento;
    
    for (int i = 0; i < 5; i++)
    {
        elemento = pila.pop();
        pilaAuxiliar.push(elemento);
    }

    for (int i = 0; i < 5; i++)
    {
        elemento = pilaAuxiliar.pop();
        pila.push(elemento);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << pila.pop() << endl;
    }
}

int main()
{
    Pila<int> pila;
    int elemento;

    cout << "Ingrese 5 elementos para la pila:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> elemento;
        pila.push(elemento);
    }

    cout << "Elementos de la pila invertida:" << endl;
    invertirPila(pila);

    return 0;
}

/*Apilar 3 elementos*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main()
{
    Pila<double> pila;

    pila.push(1.1);
    pila.push(2.2);
    pila.push(3.3);

    for (int i = 1; i <= 3; i++)
    {
        cout << pila.pop() << endl;
    }

    return 0;
}
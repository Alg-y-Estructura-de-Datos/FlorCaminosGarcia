/*Crear pila con 5 elementos*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main()
{
    Pila<int> pila;

    for (int i = 1; i <= 5; i++)
    {
        pila.push(i);
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << pila.pop() << endl;
    }

    return 0;
}

/*
int main(){
    Pila<string> pila;

    pila.push("Primero");
    pila.push("Segundo");
    pila.push("Tercero");
    pila.push("Cuarto");
    pila.push("Quinto");

    for(int i=1; i<=5; i++){
        cout << pila.pop() << endl;
    }

    return 0;
}
*/
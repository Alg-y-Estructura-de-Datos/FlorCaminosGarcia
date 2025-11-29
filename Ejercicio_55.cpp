/*Ver tope sin desapilar*/
#include <iostream>
#include "Pila/Pila.h"

using namespace std;

int main()
{
    Pila<int> pila;
    int tope;

    pila.push(10);
    pila.push(20);
    pila.push(30);

    if (!pila.esVacia())
    {
        tope = pila.pop();
        pila.push(tope);
    }

    cout << "Tope de la pila: " << tope << endl;

    cout << "Desapilando elementos:" << endl;
    while (!pila.esVacia())
    {
        cout << pila.pop() << endl;
    }

    return 0;
}

/*
int main(){
    Pila<string> pila;
    string tope;

    pila.push("Primero");
    pila.push("Segundo");
    pila.push("Tercero");

    if(!pila.esVacia()){
        tope = pila.pop();
        pila.push(tope);
    }

    cout << "Tope de la pila: " << tope << endl;

    cout << "Desapilando elementos:" << endl;
    while(!pila.esVacia()){
        cout << pila.pop() << endl;
    }

    return 0;
}
*/

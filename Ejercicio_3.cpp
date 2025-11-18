//Imprimir todos los elementos de una lista
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

int main()
{
    Lista<int> miLista;
    int nu1, nun;

    cout<< "Ingrese la cantidad de valores que desea que tenga la lista"<< endl;
    cin>> nun;

    for (int i = 0; i < nun; i++)
    {
        cout<< "Ingrese el valor del elemento en la posición" << i + 1 << endl;
        cin>> nu1;
        miLista.insertar(i, nu1);
    }

    cout<<"***LISTA INGRESADA***"<<endl;
    miLista.print();
}
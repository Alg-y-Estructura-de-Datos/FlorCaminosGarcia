/*Usar lista doble para implementar cola*/
#include <iostream>
#include "Lista/ListaDoble.h"
#include "Cola/Cola.h"

using namespace std;

int main()
{
    Cola<int> cola1, cola2;

    cola1.encolar(1);
    cola1.encolar(2);
    cola1.encolar(3);

    cola2.encolar(4);
    cola2.encolar(5);
    cola2.encolar(6);

    Cola<int> colaFusionada;

    while (!cola1.esVacia())
    {
        colaFusionada.encolar(cola1.desencolar());
    }

    while (!cola2.esVacia())
    {
        colaFusionada.encolar(cola2.desencolar());
    }

    cout << "Elementos de la cola fusionada: ";
    while (!colaFusionada.esVacia())
    {
        cout << colaFusionada.desencolar() << " ";
    }
    cout << endl;
    return 0;
}
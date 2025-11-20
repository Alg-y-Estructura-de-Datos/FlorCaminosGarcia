/*Recorrer lista circular completa*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    
    lista.insertarUltimo(10);
    lista.insertarUltimo(20);
    lista.insertarUltimo(30);

    cout << "Elementos de la lista circular recorrida completamente:" << endl;
    
    int tamanio = lista.getTamanio();
    for (int i = 0; i < tamanio * 2; i++) // Recorrer el doble del tamaño para mostrar la circularidad
    {
        cout << lista.getDato(i % tamanio) << " "; // Usar el operador módulo para ciclar
    }

    return 0;
}
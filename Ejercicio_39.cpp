/*Insertar al inicio de lista circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    
    lista.insertarUltimo(20);
    lista.insertarUltimo(30);
    lista.insertarPrimero(10); // Insertar al inicio

    cout << "Elementos de la lista circular despues de insertar al inicio:" << endl;
    
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    return 0;
}
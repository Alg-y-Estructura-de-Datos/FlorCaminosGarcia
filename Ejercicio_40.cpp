/*Insertar al final de lista circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    
    lista.insertarPrimero(10);
    lista.insertarPrimero(20);
    lista.insertarUltimo(30); // Insertar al final

    cout << "Elementos de la lista circular despues de insertar al final:" << endl;
    
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    return 0;
}
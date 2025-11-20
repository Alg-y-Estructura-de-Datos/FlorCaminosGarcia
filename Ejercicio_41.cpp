/*Eliminar primer elemento circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    
    lista.insertarUltimo(10);
    lista.insertarUltimo(20);
    lista.insertarUltimo(30);

    cout << "Elementos de la lista circular antes de eliminar el primer elemento:" << endl;
    
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }
    cout << endl;

    lista.remover(0); // Eliminar el primer elemento

    cout << "Elementos de la lista circular despues de eliminar el primer elemento:" << endl;
    
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }
    cout << endl;

    return 0;
}
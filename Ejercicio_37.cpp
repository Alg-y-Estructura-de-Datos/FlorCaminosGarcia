/*Crear lista circular con 3 elementos*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    
    lista.insertarUltimo(10);
    lista.insertarUltimo(20);
    lista.insertarUltimo(30);

    cout << "Elementos de la lista circular:" << endl;
    
    for (int i = 0; i < lista.getTamanio(); i++)
    {
        cout << lista.getDato(i) << " ";
    }

    return 0;
}
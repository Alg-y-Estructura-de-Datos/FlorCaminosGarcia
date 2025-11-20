/*Recorrer lista de fin a inicio*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void recorrerFinInicio(Lista<T> &lista)
{
    cout << "Recorriendo lista de Fin a Inicio: " << endl;

    for (int i = lista.getTamanio() - 1; i >= 0; i--)
    {
        T elemento = lista.getDato(i);
        cout << "Posicion: " << i << ": " << elemento << endl;
    }
}

int main()
{
    Lista<int> lista;

    lista.insertarUltimo(100);
    lista.insertarUltimo(200);
    lista.insertarUltimo(300);
    lista.insertarUltimo(400);

    recorrerFinInicio(lista);

    return 0;
}
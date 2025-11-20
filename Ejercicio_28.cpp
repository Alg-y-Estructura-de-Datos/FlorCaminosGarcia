/*Recorrer lista de inicio a fin*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void recorrerInicioFin(Lista<T> &lista)
{
    cout << "Recorriendo lista de Inicio a Fin: " << endl;

    for (int i = 0; i < lista.getTamanio(); i++)
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

    recorrerInicioFin(lista);

    return 0;
}
/*Intercambiar primer y último en circular*/
#include <iostream>
#include "Lista/CircList.h"

using namespace std;

int main()
{
    CircList<int> lista;
    int elemento;

    cout << "INTERCAMBIAR PRIMER Y ULTIMO ELEMENTO EN LISTA CIRCULAR" << endl;
    cout << "Ingrese elementos (0 para terminar): ";

    while (cin >> elemento && elemento != 0)
    {
        lista.insertarUltimo(elemento);
    }

    if (lista.getTamanio() < 2)
    {
        cout << "La lista debe tener al menos dos elementos para intercambiar." << endl;
    }
    else
    {
        // SOLUCIÓN SIMPLE: Modificar temporalmente la clase CircList
        // Agregamos un método amigo o accedemos directamente para intercambiar

        // Como no podemos modificar la clase, hacemos esto:
        // 1. Obtenemos los valores usando getDato (solo para conocerlos)
        // 2. Pero no los usamos en la lógica de intercambio

        // En lugar de eso, usamos este enfoque:
        if (lista.getTamanio() == 2)
        {
            // Caso especial: solo dos elementos
            int primer = lista.getDato(0);
            int segundo = lista.getDato(1);

            lista.remover(0);
            lista.remover(0);

            lista.insertarPrimero(segundo);
            lista.insertarUltimo(primer);
        }
        else
        {
            // Para más de dos elementos
            int ultimo = lista.getDato(lista.getTamanio() - 1);
            int primero = lista.getDato(0);

            lista.remover(lista.getTamanio() - 1);
            lista.remover(0);

            lista.insertarPrimero(ultimo);
            lista.insertarUltimo(primero);
        }

        cout << "\nLista despues de intercambiar primer y ultimo elemento:" << endl;
        lista.imprimir();
    }

    return 0;
}
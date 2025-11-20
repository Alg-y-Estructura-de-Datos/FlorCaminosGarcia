/*Copiar una lista enlazada donde cada nodo tiene un puntero 
adicional que puede apuntar a cualquier nodo de la lista o
 a NULL.*/
#include <iostream>
#include "Lista/Lista.h"

using namespace std;

template <class T>
void crearCopia(Lista<T>& original) {
    Lista<T> copia;
    int n = original.getTamanio();

    for (int i = 0; i < n; i++) {
        copia.insertarUltimo(original.getDato(i));
    }

    cout << "Copia de la lista creada: ";
    for (int i = 0; i < copia.getTamanio(); i++) {
        cout << copia.getDato(i) << " ";
    }
    cout << endl;
}

int main()
{
    Lista<int> lista;
    int n, dato;

    cout << "Ingrese la cantidad de elementos para la lista: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> dato;
        lista.insertarUltimo(dato);
    }

    crearCopia(lista);

    return 0;
}
/*Convertir lista simple a circular*/
#include <iostream>
#include "Lista/Lista.h"
#include "Lista/CircList.h"

using namespace std;

// Función para convertir una lista simple en circular
template <class T>
CircList<T> convertirASimpleACircular(const Lista<T> &listaSimple)
{
    CircList<T> listaCircular;

    for (int i = 0; i < listaSimple.getTamanio(); i++)
    {
        listaCircular.insertarUltimo(listaSimple.getDato(i));
    }

    return listaCircular;
}

int main()
{
    Lista<int> listaSimple;

    // Crear una lista simple
    listaSimple.insertarUltimo(10);
    listaSimple.insertarUltimo(20);
    listaSimple.insertarUltimo(30);
    listaSimple.insertarUltimo(40);

    cout << "Lista Simple: ";
    listaSimple.print(); // 10->20->30->40->NULL

    // Convertir a lista circular
    CircList<int> listaCircular = convertirASimpleACircular(listaSimple);

    cout << "Lista Circular (mostrando 8 elementos para demostrar circularidad): ";
    for (int i = 0; i < 8; i++) {
        cout << listaCircular.getDato(i % listaSimple.getTamanio()) << "->";
    }
    
    return 0;
}